package com.demo20.case2.repository.impl;

import com.demo20.case2.repository.impl.mapper.RewardMapper;
import com.demo20.case2.entity.Reward;
import com.demo20.case2.repository.RewardRepo;
import com.demo20.case2.repository.impl.builder.RewardBuilder;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

@Component
public class RewardRepoImpl implements RewardRepo {
    @Resource
    RewardMapper rewardMapper;

    @Override
    public Reward save(Reward reward) {
        return null;
    }
}
