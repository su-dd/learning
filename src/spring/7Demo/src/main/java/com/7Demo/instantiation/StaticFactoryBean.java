package com.7Demo.instantiation;

import org.springframework.context.annotation.Bean;

public class StaticFactoryBean {
    @Bean(name="schoolStaticFactory")
    public static School createSchool() {
        return new School();
    }

    @Bean(name="studentStaticFactory")
    public static Student createStudent() {
        return new Student();
    }
}
