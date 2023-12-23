package com.demo20.case1.service.impl;
/**
 * 风险控制
 *
 * 内容：查看 库存等
 * */

import com.demo20.case1.service.RiskControlService;
import org.springframework.stereotype.Service;

@Service
public class RiskControlServiceImpl implements RiskControlService {
    // 查看库存
    @Override
    public boolean check(String idCard, String label) {
        return true;
    }
}
