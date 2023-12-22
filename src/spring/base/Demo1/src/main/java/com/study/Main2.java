package com.study;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

public class Main2 {
    public static void main(String[] args) {

        ApplicationContext applicationContext = new FileSystemXmlApplicationContext("src/main/resources/applicationContext.xml");
        //ApplicationContext applicationContext = new FileSystemXmlApplicationContext("classpath:applicationContext.xml");
        //ApplicationContext applicationContext = new FileSystemXmlApplicationContext(new String[]{"classpath:applicationContext.xml","classpath:SpringTest.xml"});
        //ApplicationContext applicationContext = new FileSystemXmlApplicationContext("classpath:/*.xml");
        Student student = (Student) applicationContext.getBean("student");
        student.study();
    }
}
