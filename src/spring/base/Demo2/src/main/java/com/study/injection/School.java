package com.study.injection;

import java.util.List;
import java.util.Map;
import java.util.Properties;

public class School {
    private String name;
    // 学生名
    private List<String> studentNames;

    // 数学课
    private List<Student> mathClass;

    // 学生表
    private Map<String, Student> studentMap;

    //
    private Properties classTeacher;


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<String> getStudentNames() {
        return studentNames;
    }

    public void setStudentNames(List<String> studentNames) {
        this.studentNames = studentNames;
    }

    public List<Student> getMathClass() {
        return mathClass;
    }

    public void setMathClass(List<Student> mathClass) {
        this.mathClass = mathClass;
    }

    public Map<String, Student> getStudentMap() {
        return studentMap;
    }

    public void setStudentMap(Map<String, Student> studentMap) {
        this.studentMap = studentMap;
    }

    public Properties getClassTeacher() {
        return classTeacher;
    }

    public void setClassTeacher(Properties classTeacher) {
        this.classTeacher = classTeacher;
    }

    @Override
    public String toString() {
        return "School{" +
                "name='" + name + '\'' +
                ", studentNames=" + studentNames +
                ", mathClass=" + mathClass +
                ", studentMap=" + studentMap +
                '}';
    }
}
