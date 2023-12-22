package com.spring.demo30.service.impl;


import com.alibaba.cola.dto.MultiResponse;
import com.alibaba.cola.dto.Response;
import com.spring.demo30.mapper.SchedulerTaskMapper;
import com.spring.demo30.mapper.TaskRunnableMapper;
import com.spring.demo30.pojo.Task;
import com.spring.demo30.pojo.TaskDTO;
import com.spring.demo30.pojo.TaskRunnable;
import com.spring.demo30.runnable.Taskable;
import com.spring.demo30.service.TaskSchedulerService;
import org.springframework.beans.BeanUtils;
import org.springframework.scheduling.concurrent.ThreadPoolTaskScheduler;
import org.springframework.scheduling.support.CronExpression;
import org.springframework.scheduling.support.CronTrigger;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;
import java.util.Objects;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ScheduledFuture;

@Service
public class TaskSchedulerServiceImpl implements TaskSchedulerService {
    //线程池任务调度
    private ThreadPoolTaskScheduler threadPoolTaskScheduler = new ThreadPoolTaskScheduler();
    //正在运行的任务
    public static ConcurrentHashMap<Long, ScheduledFuture> runTasks = new ConcurrentHashMap<>(10);

    @Resource
    SchedulerTaskMapper schedulerTaskMapper;

    @Resource
    TaskRunnableMapper taskRunnableMapper;

    /**
     * 无参构造，可以填充
     * 初始化线程池任务调度
     */
    public TaskSchedulerServiceImpl(){
        this.threadPoolTaskScheduler.setPoolSize(10);
        this.threadPoolTaskScheduler.setThreadNamePrefix("task-thread-");
        this.threadPoolTaskScheduler.setWaitForTasksToCompleteOnShutdown(true);
        this.threadPoolTaskScheduler.initialize();
    }

    @Override
    public MultiResponse<Task> tasks() {
        List<Task> taskList = schedulerTaskMapper.findAll();
        return MultiResponse.of(taskList);
    }

    @Override
    public MultiResponse<TaskRunnable> runnables() {
        List<TaskRunnable> taskRunnableList = taskRunnableMapper.findAll();
        return MultiResponse.of(taskRunnableList);
    }

    @Override
    @Transactional
    public Response start(Long taskId) {
        // 如果已经启动，则
        if (TaskSchedulerServiceImpl.runTasks.containsKey(taskId)) {
            return Response.buildSuccess();
        }

        try {
            Task task = schedulerTaskMapper.findById(taskId);

            //获取并实例化Runnable任务类
            if (null == task.getRunnableId()) {
                return Response.buildFailure("400","任务的执行项，未定义或错误");
            }

            TaskRunnable taskRunnable = taskRunnableMapper.findById(task.getRunnableId());
            if (null == taskRunnable) {
                return Response.buildFailure("400","任务的执行项，未定义或错误");
            }

            Class<?> clazz = Class.forName(taskRunnable.getClasspath());
            Taskable runnable = (Taskable)clazz.newInstance();

            if (null == runnable) {
                return Response.buildFailure("400","任务的 执行项未能成功创建，请联系程序员，做后台处理。");
            }

            if (!runnable.setParams(task.getParams())) {
                return Response.buildFailure("400","任务的 参数配置 错误");
            }

            if (!CronExpression.isValidExpression(task.getExpr())) {
                return Response.buildFailure("400","任务的 Cron 表达式错误");
            }

            //Cron表达式
            CronTrigger cron = new CronTrigger(task.getExpr());

            //执行，并put到runTasks
            TaskSchedulerServiceImpl.runTasks.put(
                    taskId, Objects.requireNonNull(this.threadPoolTaskScheduler.schedule(runnable, cron)));

            task.setStatus(new Long(1));
            schedulerTaskMapper.update(task);

            return Response.buildSuccess();
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException e) {
            e.printStackTrace();
            return Response.buildFailure("400", "任务启动失败");
        }
    }

    @Override
    @Transactional
    public Response stop(Long taskId) {
        if (!TaskSchedulerServiceImpl.runTasks.containsKey(taskId)) {
            return Response.buildSuccess();
        }

        TaskSchedulerServiceImpl.runTasks.get(taskId).cancel(true);
        TaskSchedulerServiceImpl.runTasks.remove(taskId);
        Task task = schedulerTaskMapper.findById(taskId);
        task.setStatus(new Long(0));
        schedulerTaskMapper.update(task);
        return Response.buildSuccess();
    }

    @Override
    @Transactional
    public Response save(TaskDTO taskDTO) {
        Task task = new Task();
        BeanUtils.copyProperties(taskDTO, task);

        if ((null == task.getId()) || (null == schedulerTaskMapper.findById(task.getId()))) {
            task.setId(null);
            schedulerTaskMapper.add(task);
        } else {
            this.stop(task.getId());
            schedulerTaskMapper.update(task);
        }
        return Response.buildSuccess();
    }

    @Override
    @Transactional
    public Response delete(Long taskId) {
        this.stop(taskId);
        schedulerTaskMapper.delete(taskId);
        return Response.buildSuccess();
    }

    @Override
    public Response resume() {
        List<Task> taskList = schedulerTaskMapper.findAll();

        taskList.forEach(task -> {
            if (1 == task.getStatus()) {
                this.start(task.getId());
            }
        });
        return Response.buildSuccess();
    }
}