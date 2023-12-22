package com.7Demo.instantiation;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext_instantiation.xml");
        School school = (School)applicationContext.getBean("school");
        school.setName("小学");
        System.out.println(school);

        Student student = (Student)applicationContext.getBean("student");
        System.out.println(student);
    }
}
