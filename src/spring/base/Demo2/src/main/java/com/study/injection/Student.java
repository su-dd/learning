package com.study.injection;

public class Student {
    private String name;
    private int age;
    private Information information;

    public Student() {
    }

    public Student(String name, int age, Information information) {
        this.name = name;
        this.age = age;
        this.information = information;
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

    public Information getInformation() {
        return information;
    }

    public void setInformation(Information information) {
        this.information = information;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", " + information.toString() +
                '}';
    }
}
