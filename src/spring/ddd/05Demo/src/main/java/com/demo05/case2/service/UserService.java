package com.demo05.case2.service;

import com.demo05.case2.dp.Address;
import com.demo05.case2.dp.Name;
import com.demo05.case2.dp.PhoneNum;
import com.demo05.case2.pojo.User;

public interface UserService {
    public User register(Name name, PhoneNum phone, Address address);
}
