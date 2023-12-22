package com.spring.demo30.mapper;


import com.spring.demo30.pojo.Task;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface SchedulerTaskMapper {
    void add(Task task);
    void update(Task task);
    void delete(Long id);
    List<Task> findAll();
    Task findById(Long id);
}
