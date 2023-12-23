package com.demo30.case2.domain.ability.impl;
/**
 * 手机号码实名制验证： 借用第三方验证
 *
 * 如：电信，联通，移动
 *
 * */


import com.demo30.case2.domain.ability.RealnameService;
import com.demo30.case2.domain.model.valueobjects.Name;
import com.demo30.case2.domain.model.valueobjects.PhoneNumber;
import com.demo30.case2.domain.model.valueobjects.RealnameInfo;
import org.springframework.stereotype.Service;

import javax.xml.bind.ValidationException;

@Service
public class RealnameServiceImpl implements RealnameService {

    @Override
    public RealnameInfo get(Name name, PhoneNumber phoneNumber) throws ValidationException {
        return new RealnameInfo(name, phoneNumber);
    }
}
