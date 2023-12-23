package com.demo30.case2.infrastructure.gatewayimpl.database.mapper;

import com.demo30.case2.infrastructure.gatewayimpl.database.dataobject.RewardDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface RewardMapper {
    public void insert(RewardDO rewardDO);
}
