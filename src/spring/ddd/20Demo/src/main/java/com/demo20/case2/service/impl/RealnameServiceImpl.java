package com.demo20.case2.service.impl;
/**
 * 手机号码实名制验证： 借用第三方验证
 *
 * 如：电信，联通，移动
 *
 * */

import com.demo20.case2.service.RealnameService;
import com.demo20.case2.vo.Name;
import com.demo20.case2.vo.PhoneNumber;
import com.demo20.case2.vo.RealnameInfo;
import org.springframework.stereotype.Service;

import javax.xml.bind.ValidationException;

@Service
public class RealnameServiceImpl implements RealnameService {

    @Override
    public RealnameInfo get(Name name, PhoneNumber phoneNumber) throws ValidationException {
        return new RealnameInfo(name, phoneNumber);
    }
}
