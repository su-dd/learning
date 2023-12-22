package com.study.instantiation;

public class Student {
    private String name;
    private int age;

    public Student() {
        System.out.println("——运行 Student 无参构造——");
    }

    public void initValue() {
        System.out.println("——运行 Student 初始化函数——");
    }

    public void destroyValue() {
        System.out.println("——运行 Student 销毁函数——");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
