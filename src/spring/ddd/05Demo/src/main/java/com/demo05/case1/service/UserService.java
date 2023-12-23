package com.demo05.case1.service;

import com.demo05.case1.pojo.User;

import javax.xml.bind.ValidationException;

public interface UserService {
    public User register(String name, String phone, String address) throws ValidationException;
}
