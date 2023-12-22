package com.spring.demo30.service;


import com.alibaba.cola.dto.MultiResponse;
import com.alibaba.cola.dto.Response;
import com.spring.demo30.pojo.Task;
import com.spring.demo30.pojo.TaskDTO;
import com.spring.demo30.pojo.TaskRunnable;

public interface TaskSchedulerService {

    MultiResponse<Task> tasks();
    MultiResponse<TaskRunnable> runnables();
    Response start(Long taskId);
    Response stop(Long taskId);
    Response save(TaskDTO task);
    Response delete(Long taskId);

    Response resume();
}
