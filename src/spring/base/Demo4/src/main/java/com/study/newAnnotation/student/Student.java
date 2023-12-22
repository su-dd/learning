package com.study.newAnnotation.student;

public interface Student {
    public default String info() {
        return toString();
    }
}
