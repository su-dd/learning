package com.demo30.case1.service;

import com.demo30.case1.vo.Name;
import com.demo30.case1.vo.PhoneNumber;
import com.demo30.case1.vo.RealnameInfo;

import javax.xml.bind.ValidationException;

public interface RealnameService {
    RealnameInfo get(Name name, PhoneNumber phoneNumber) throws ValidationException;
}
