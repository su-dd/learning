package com.spring.demo40;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class Demo40 implements CommandLineRunner {
    @Autowired
    TaskA taskA;

    @Override
    public void run(String... args) throws Exception {
        // 方式1：@Autowired注解的对象进行调用
        System.out.println("test1:");
        taskA.run();
    }

    public static void main(String[] args) {
        SpringApplication.run(Demo40.class, args);

        System.out.println("test2:");
        // 方式2: new初始化的变量进行调用
        try {
            TaskA task = new TaskA();
            task.run();
        } catch (Exception e) {
            e.printStackTrace();
        }


        System.out.println("test3:");
        // 方式3: 通过SpringContext封装创建
        try {
            TaskA task = SpringContextUtil.getBean(TaskA.class);
            task.run();
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println("test4:");
        // 方式4: 通过SpringContext封装创建
        try {
            TaskA task = (TaskA) SpringContextUtil.getBean("taskA");
            task.run();
        } catch (Exception e) {
            e.printStackTrace();
        }


    }
}
