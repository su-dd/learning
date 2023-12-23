package com.demo30.case1.service.impl;
/**
 * 风险控制
 *
 * 内容：查看 库存等
 * */


import com.demo30.case1.entity.User;
import com.demo30.case1.service.RiskControlService;
import org.springframework.stereotype.Service;

@Service
public class RiskControlServiceImpl implements RiskControlService {
    // 查看库存
    @Override
    public boolean check(User user) {
        return false;
    }
}
