package com.7Demo.newAnnotation;

import com.study.newAnnotation.student.Student;
import org.springframework.beans.factory.annotation.Autowired;

import javax.annotation.Resource;
import javax.naming.Name;
import java.util.List;
import java.util.Map;

public class School {

    @Resource
    private List<Student> studentList;

    @Autowired
    private Map<String, Student> studentMap;

    private String name;

    public School() {
    }

    public School(String name) {
        this.name = name;
    }

    public School(List<Student> studentList, Map<String, Student> studentMap, String name) {
        this.studentList = studentList;
        this.studentMap = studentMap;
        this.name = name;
    }

    @Override
    public String toString() {
        return "School{" +
                "studentList=" + studentList +
                ", studentMap=" + studentMap +
                ", name='" + name + '\'' +
                '}';
    }
}
