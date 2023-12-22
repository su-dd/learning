package com.spring.demo40;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class TaskA {

    @Autowired
    TaskB taskB;

    void run() {
        System.out.println("TaskA is run");
        taskB.run();
    }
}
