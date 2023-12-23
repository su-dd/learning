package com.demo20.case1.repository;

import com.demo20.case1.pojo.RewardDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface RewardMapper {
    public void insert(RewardDO rewardDO);
}
