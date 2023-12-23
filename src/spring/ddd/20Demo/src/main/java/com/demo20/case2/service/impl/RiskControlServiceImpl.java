package com.demo20.case2.service.impl;
/**
 * 风险控制
 *
 * 内容：查看 库存等
 * */

import com.demo20.case2.entity.User;
import com.demo20.case2.service.RiskControlService;
import org.springframework.stereotype.Service;

@Service
public class RiskControlServiceImpl implements RiskControlService {
    // 查看库存
    @Override
    public boolean check(User user) {
        return false;
    }
}
