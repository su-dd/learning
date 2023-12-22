package com.spring.demo30.runnable.impl;

import com.spring.demo30.runnable.Taskable;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;

import java.text.SimpleDateFormat;
import java.util.Date;

@Slf4j
@Component
public class MyRunnable2 implements Taskable {

    @Override
    public void run() {
        log.info("MyRunnable2  {}",new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date()));
    }

    @Override
    public boolean setParams(String params) {
        return true;
    }
}