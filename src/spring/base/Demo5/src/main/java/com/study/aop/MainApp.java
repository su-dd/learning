package com.study.aop;

import com.study.aop.imp.StudentAspect;
import org.aspectj.lang.annotation.DeclareParents;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");

        Student student = (Student)applicationContext.getBean("student");
        student.study("语文", "大王");
        System.out.println("");

        People people = (People)student;
        people.eat();
    }
}
