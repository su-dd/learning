package com.study.instantiation;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");

        School school1 = (School)applicationContext.getBean("school");
        School school2 = (School)applicationContext.getBean("school");
        school1.setName("小学");
        school2.setName("中学");
        System.out.println(school1.getName());
        System.out.println(school2.getName());

        Student student1 = (Student)applicationContext.getBean("student");
        Student student2 = (Student)applicationContext.getBean("student");
        student1.setName("小明");
        student2.setName("小红");
        System.out.println(student1.getName());
        System.out.println(student2.getName());
    }
}
