package com.spring.demo30.runnable;

public interface Taskable extends Runnable {
    public abstract boolean setParams(String params);
}
