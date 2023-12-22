package com.7Demo.newAnnotation;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class MainApp {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new AnnotationConfigApplicationContext(MainScanConfig.class);
        Information information = (Information)applicationContext.getBean("information110");
        System.out.println(information.toString());

        School school = (School)applicationContext.getBean("school");
        System.out.println(school.toString());
    }
}
