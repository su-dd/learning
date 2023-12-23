package com.demo30.case2.infrastructure.gatewayimpl.database.mapper;

import com.demo30.case2.infrastructure.gatewayimpl.database.dataobject.UserDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface UserMapper {
    public UserDO save(UserDO userDO);
    public UserDO insert(UserDO userDO);
}
