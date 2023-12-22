package com.spring.demo30.runnable.impl;

import com.spring.demo30.runnable.Taskable;
import lombok.extern.slf4j.Slf4j;

import java.text.SimpleDateFormat;
import java.util.Date;

@Slf4j
public class MyRunnable1 implements Taskable {
    @Override
    public void run() {
        log.info("MyRunnable1  {}",new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date()));
    }

    @Override
    public boolean setParams(String params) {
        return true;
    }
}