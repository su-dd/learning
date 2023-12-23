package com.demo30.case1.repository.impl.mapper;

import com.demo30.case1.repository.impl.dateobject.RewardDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface RewardMapper {
    public void insert(RewardDO rewardDO);
}
