package com.study.aop;

import com.study.aop.imp.People;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;

public class StudentAspect implements People {
    public void before(JoinPoint joinPoint) {
        //System.out.println(joinPoint.getSignature().getName());
        System.out.println("before, 前置增强 ... " + joinPoint.getArgs()[0]);
    }

    public void after(String course, String teacher) {
        System.out.println("after-returning, 后置增强 ... ");
    }

    public void around(ProceedingJoinPoint joinPoint) throws Throwable {
        System.out.println("around, 环绕增强 ... ");

        Object[] args = joinPoint.getArgs();
        if (args.length > 0) {
            System.out.print("Arguments passed: " );
            for (int i = 0; i < args.length; i++) {
                System.out.print("arg "+(i+1)+": "+args[i]);
            }
        }

        joinPoint.proceed(args);

        System.out.println("around, 运行完 ... ");
    }

    public void throwing() {
        System.out.println("after-throwing, 异常增强 ... ");
    }

    public void afterAll() {
        System.out.println("after, 最终通知增强 ... ");
    }

    @Override
    public void eat() {
        System.out.println("吃 吃 吃，就知道吃 ... ");
    }
}
