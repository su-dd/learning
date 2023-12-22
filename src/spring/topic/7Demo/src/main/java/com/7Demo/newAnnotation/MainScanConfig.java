package com.7Demo.newAnnotation;

import com.study.newAnnotation.student.Student;
import org.springframework.beans.factory.annotation.Autowire;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Import;

import javax.annotation.Resource;
import java.util.List;
import java.util.Map;

@ComponentScan(value = "com.study.newAnnotation")

@Import(InformationConfig.class)

@Configuration
public class MainScanConfig {

    @Bean(name = "school")
    public School getSchool() {
        return new School("小学");
    }
}
