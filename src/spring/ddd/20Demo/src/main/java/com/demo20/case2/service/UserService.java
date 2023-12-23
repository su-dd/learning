package com.demo20.case2.service;

import com.demo20.case2.entity.User;
import com.demo20.case2.vo.Name;
import com.demo20.case2.vo.PhoneNumber;

import javax.xml.bind.ValidationException;

public interface UserService {
    public User register(Name name, PhoneNumber phone) throws ValidationException;
}
