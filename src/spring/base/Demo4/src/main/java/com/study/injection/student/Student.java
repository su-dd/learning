package com.study.injection.student;

public interface Student {
    public default String info() {
        return toString();
    }
}
