package com.study.aop.imp;

import com.study.aop.People;
import com.study.aop.Student;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.stereotype.Component;

@Component("studentAspect")
@Aspect
public class StudentAspect implements People {

    @DeclareParents(value = "com.study.aop.Student", defaultImpl = com.study.aop.imp.StudentAspect.class)
    public People people;

    @Before("execution(void com.study.aop.Student.study(..))")
    public void before(JoinPoint joinPoint) {
        //System.out.println(joinPoint.getSignature().getName());
        System.out.println("before, 前置增强 ... " + joinPoint.getArgs()[0]);
    }

    //@AfterReturning(pointcut = "execution( * com.study.aop.Student.study(String,String)) && args(course, teacher)")
    @AfterReturning(pointcut = "execution( * com.study.aop.Student.study(String,String)) && args(course, teacher)", argNames = "course, teacher")
    public void after(String course, String teacher) {
        System.out.println("after-returning, 后置增强 ... " + teacher);
    }

    @Around(value = "execution( * com.study.aop.Student.study(..))")
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

    @AfterThrowing(value = "execution( * com.study.aop.Student.study(..))")
    public void throwing() {
        System.out.println("after-throwing, 异常增强 ... ");
    }

    @After(value = "StudentAspect.pointcut(course, teacher)", argNames = "teacher, course")
    public void afterAll(String teacher, String course) {
        System.out.println("after, 最终通知增强 ... " + course + "_" + teacher);
    }


    @Override
    public void eat() {
        System.out.println("吃 吃 吃，就知道吃 ... ");
    }


    @Pointcut(value = "execution( * com.study.aop.Student.study(String,String)) && args(p1, p2)", argNames = "p1, p2")
    public void pointcut(String p1, String p2){}
}
