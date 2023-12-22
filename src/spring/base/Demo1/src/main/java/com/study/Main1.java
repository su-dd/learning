package com.study;

import javafx.application.Application;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Main1 {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        //ApplicationContext applicationContext = new ClassPathXmlApplicationContext("file:E:/applicationContext.xml");
        //ApplicationContext applicationContext = new ClassPathXmlApplicationContext(new String[]{"applicationContext.xml","SpringTest.xml"});
        //ApplicationContext applicationContext = new ClassPathXmlApplicationContext("classpath:/*.xml");
        Student student = (Student) applicationContext.getBean("student");
        student.study();
    }
}