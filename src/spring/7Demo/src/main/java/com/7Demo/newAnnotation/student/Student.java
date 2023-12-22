package com.7Demo.newAnnotation.student;

public interface Student {
    public default String info() {
        return toString();
    }
}
