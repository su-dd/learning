package com.spring.demo30.pojo;

import lombok.Data;

import java.io.Serializable;
import java.sql.Date;

/**
 * 动态定时任务表
 * 重要属性：唯一表id、Runnable任务类、Cron表达式，
 * 其他的都是一些额外补充说明属性
 */
@Data
public class Task implements Serializable {
    private Long id;//定时任务id
    private String name;//定时任务名称
    private String desc;//定时任务描述
    private String expr;//定时任务Cron表达式
    private Long status;//定时任务状态，0停用 1启用
    private Long runnableId;//定时任务的Runnableid
    private String params;//定时任务的参数
    private Date createTime;//创建时间
    private Date updateTime;//更新时间
}