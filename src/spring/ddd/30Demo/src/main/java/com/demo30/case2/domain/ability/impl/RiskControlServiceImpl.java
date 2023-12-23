package com.demo30.case2.domain.ability.impl;
/**
 * 风险控制
 *
 * 内容：查看 库存等
 * */


import com.demo30.case2.domain.ability.RiskControlService;
import com.demo30.case2.domain.model.entities.User;
import org.springframework.stereotype.Service;

@Service
public class RiskControlServiceImpl implements RiskControlService {
    // 查看库存
    @Override
    public boolean check(User user) {
        return false;
    }
}
