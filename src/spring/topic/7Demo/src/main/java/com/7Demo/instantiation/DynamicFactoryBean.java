package com.7Demo.instantiation;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Controller;

@Component("dynamicFactoryBean")
@Scope("singleton")
public class DynamicFactoryBean {
    @Bean(name="schoolDynamicFactory")
    public School createSchool() {
        return new School();
    }

    @Bean(name="studentDynamicFactory")
    public Student createStudent() {
        return new Student();
    }
}
