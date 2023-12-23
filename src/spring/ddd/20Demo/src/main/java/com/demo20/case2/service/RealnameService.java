package com.demo20.case2.service;

import com.demo20.case2.vo.Name;
import com.demo20.case2.vo.PhoneNumber;
import com.demo20.case2.vo.RealnameInfo;

import javax.xml.bind.ValidationException;

public interface RealnameService {
    RealnameInfo get(Name name, PhoneNumber phoneNumber) throws ValidationException;
}
