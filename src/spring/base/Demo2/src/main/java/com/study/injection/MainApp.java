package com.study.injection;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext2.xml");

        Student studentXiaoMing = (Student) applicationContext.getBean("studentXiaoMing");
        System.out.println(studentXiaoMing.toString());

        Student studentXiaoHong = (Student) applicationContext.getBean("studentXiaoHong");
        System.out.println(studentXiaoHong.toString());

        School school = (School)applicationContext.getBean("school");
        System.out.println(school.toString());
    }
}
