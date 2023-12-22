package com.study.instantiation;

public class StaticFactoryBean {
    public static School createSchool() {
        return new School();
    }

    public static Student createStudent() {
        return new Student();
    }
}
