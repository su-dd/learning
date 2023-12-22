package com.spring.demo30.pojo;

import lombok.Data;

import java.io.Serializable;

@Data
public class TaskRunnable implements Serializable {
    private Long id;//id
    private String name;//名称
    private String classpath;//类路径
    private String params;//参数
}
