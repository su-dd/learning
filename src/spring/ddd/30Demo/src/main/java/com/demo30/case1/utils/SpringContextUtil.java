package com.demo30.case1.utils;

import org.springframework.beans.BeansException;
import org.springframework.context.ApplicationContext;
import org.springframework.context.ApplicationContextAware;
import org.springframework.stereotype.Component;

/**
 * 动态加载Bean
 */
@Component
public class SpringContextUtil implements ApplicationContextAware {
    // Spring应用上下文
    private static ApplicationContext applicationContext;

    @Override
    public void setApplicationContext(ApplicationContext applicationContext) throws BeansException {
        SpringContextUtil.applicationContext = applicationContext;
    }

    public static ApplicationContext getApplicationContext() {
        return applicationContext;
    }

    public static Object getBean(String name) throws BeansException {
        return applicationContext.getBean(name);
    }

    public static  <T> T getBean(Class<T> requiredType) {
        return applicationContext.getBean(requiredType);
    }
}
