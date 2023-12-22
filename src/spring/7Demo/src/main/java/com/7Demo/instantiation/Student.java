package com.7Demo.instantiation;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Repository;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

@Repository("student")
@Scope("prototype")
public class Student {

    private String name;

    private int age;

    public Student() {
        System.out.println("——运行 Student 无参构造——");
    }

    @PostConstruct
    public void initValue() {
        System.out.println("——运行 Student 初始化函数——");
    }

    @PreDestroy
    public void destroyValue() {
        System.out.println("——运行 Student 销毁函数——");
    }

    public String getName() {
        return name;
    }

    @Value("小明")
    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    @Value("16")
    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}
