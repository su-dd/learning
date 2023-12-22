package com.7Demo.newAnnotation;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class InformationConfig {
    @Bean(name = "information110")
    public Information getInformation110(){
        return new Information("110");
    }

    @Bean(name = "information112")
    public Information getInformation112(){
        return new Information("112");
    }
}
