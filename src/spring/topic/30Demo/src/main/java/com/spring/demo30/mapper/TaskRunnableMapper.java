package com.spring.demo30.mapper;

import com.spring.demo30.pojo.TaskRunnable;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface TaskRunnableMapper {
    List<TaskRunnable> findAll();
    TaskRunnable findById(Long id);
}
