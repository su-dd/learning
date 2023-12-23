package com.demo20.case1.service.impl;
/**
 * 手机号码实名制验证： 借用第三方验证
 *
 * 如：电信，联通，移动
 *
 * */

import com.demo20.case1.pojo.TelecomInfoDTO;
import com.demo20.case1.service.TelecomRealnameService;
import org.springframework.stereotype.Service;

@Service
public class TelecomRealnameServiceImpl implements TelecomRealnameService {
    // 调用外部rpc
    @Override
    public TelecomInfoDTO getRealnameInfo(String number) {
        return null;
    }
}
