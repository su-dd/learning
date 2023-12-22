package com.study.instantiation;

public class DynamicFactoryBean {
    public School createSchool() {
        return new School();
    }

    public Student createStudent() {
        return new Student();
    }
}
