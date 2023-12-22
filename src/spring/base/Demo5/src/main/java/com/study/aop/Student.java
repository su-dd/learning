package com.study.aop;

import org.aspectj.lang.annotation.DeclareParents;
import org.springframework.stereotype.Component;

@Component("student")
public class Student {
    public void study(String course, String teacher) {
        System.out.println("study  " + course + " Teacher:" + teacher);
    }
}
