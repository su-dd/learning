package com.spring.demo30.pojo;

import lombok.Data;

import java.io.Serializable;

@Data
public class TaskDTO implements Serializable {
    private Long id;//定时任务id
    private String name;//定时任务名称
    private String desc;//定时任务描述
    private String expr;//定时任务Cron表达式
    private Long status;//定时任务状态，0停用 1启用
    private Long runnableId;//定时任务的Runnableid
    private String params;//定时任务的参数
}
