package com.demo20.case2.repository.impl.mapper;

import com.demo20.case2.repository.impl.dateobject.RewardDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface RewardMapper {
    public void insert(RewardDO rewardDO);
}
