package com.study.injection;

import com.study.injection.info.Information;
import com.study.injection.student.Student;
import com.study.injection.student.impl.StudentXiaoHong;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext_injection.xml");
        Information information = (Information) applicationContext.getBean("information110");
        System.out.println(information.info());

        Student studentXiaoHong = (Student)applicationContext.getBean("studentXiaoHong");
        System.out.println(studentXiaoHong.info());

    }
}
