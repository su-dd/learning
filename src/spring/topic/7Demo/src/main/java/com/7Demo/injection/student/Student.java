package com.7Demo.injection.student;

public interface Student {
    public default String info() {
        return toString();
    }
}
