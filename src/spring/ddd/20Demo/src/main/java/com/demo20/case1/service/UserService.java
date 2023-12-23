package com.demo20.case1.service;

import com.demo20.case1.pojo.Name;
import com.demo20.case1.pojo.PhoneNumber;
import com.demo20.case1.pojo.UserDO;

import javax.xml.bind.ValidationException;

public interface UserService {
    public UserDO register(Name name, PhoneNumber phone) throws ValidationException;
}
