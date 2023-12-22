package com.study.instantiation;

public class School {
    private String name;

    public School() {
        System.out.println("——运行 School 无参构造——");
    }

    public void initValue() {
        System.out.println("——运行 School 初始化函数——");
    }

    public void destroyValue() {
        System.out.println("——运行 School 销毁函数——");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
