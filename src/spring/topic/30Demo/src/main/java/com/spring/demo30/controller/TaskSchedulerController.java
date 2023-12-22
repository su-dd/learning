package com.spring.demo30.controller;


import com.alibaba.cola.dto.MultiResponse;
import com.alibaba.cola.dto.Response;
import com.spring.demo30.pojo.Task;
import com.spring.demo30.pojo.TaskDTO;
import com.spring.demo30.pojo.TaskRunnable;
import com.spring.demo30.service.TaskSchedulerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;


@RestController
@RequestMapping("/scheduler")
public class TaskSchedulerController {

    @Autowired
    TaskSchedulerService taskSchedulerService;

    /**
     * 更新一个动态定时任务
     */
    @RequestMapping(value = "/tasks", method = RequestMethod.POST)
    @ResponseBody
    public MultiResponse<Task> tasks() {
        return taskSchedulerService.tasks();
    }

    /**
     * 更新一个动态定时任务
     */
    @RequestMapping(value = "/runnables", method = RequestMethod.POST)
    @ResponseBody
    public MultiResponse<TaskRunnable> runnables() {
        return taskSchedulerService.runnables();
    }

    /**
     * 启动一个动态定时任务
     */
    @RequestMapping(value = "/start", method = RequestMethod.POST)
    @ResponseBody
    public Response start(@RequestBody TaskDTO taskDTO){
        return taskSchedulerService.start(taskDTO.getId());
    }

    /**
     * 停止一个动态定时任务
     */
    @RequestMapping(value = "/stop", method = RequestMethod.POST)
    @ResponseBody
    public Response stop(@RequestBody TaskDTO taskDTO){
        return taskSchedulerService.stop(taskDTO.getId());
    }

    /**
     * 更新一个动态定时任务
     */
    @RequestMapping(value = "/save", method = RequestMethod.POST)
    @ResponseBody
    public Response save(@RequestBody TaskDTO taskDTO) {
        return taskSchedulerService.save(taskDTO);
    }

    /**
     * 删除任务
     */
    @RequestMapping(value = "/delete", method = RequestMethod.POST)
    @ResponseBody
    public Response delete(@RequestBody TaskDTO taskDTO) {
        return taskSchedulerService.delete(taskDTO.getId());
    }
}
