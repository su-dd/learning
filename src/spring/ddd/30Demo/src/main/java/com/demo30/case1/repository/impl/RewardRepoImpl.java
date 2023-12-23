package com.demo30.case1.repository.impl;

import com.demo30.case1.repository.impl.mapper.RewardMapper;
import com.demo30.case1.entity.Reward;
import com.demo30.case1.repository.RewardRepo;
import com.demo30.case1.repository.impl.builder.RewardBuilder;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

@Component
public class RewardRepoImpl implements RewardRepo {
    @Resource
    RewardMapper rewardMapper;
    @Autowired
    RewardBuilder rewardBuilder;

    @Override
    public Reward save(Reward reward) {
        return null;
    }
}
