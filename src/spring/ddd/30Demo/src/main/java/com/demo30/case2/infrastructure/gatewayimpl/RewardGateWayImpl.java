package com.demo30.case2.infrastructure.gatewayimpl;

import com.demo30.case2.domain.gateway.RewardGateWay;
import com.demo30.case2.domain.model.entities.Reward;
import com.demo30.case2.infrastructure.gatewayimpl.database.mapper.RewardMapper;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

@Component
public class RewardGateWayImpl implements RewardGateWay {
    @Resource
    RewardMapper rewardMapper;
    @Override
    public Reward save(Reward reward) {
        return null;
    }
}
