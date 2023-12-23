package com.demo20.case1.repository;

import com.demo20.case1.pojo.UserDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface UserMapper {
    public UserDO save(UserDO userDO);
    public UserDO insert(UserDO userDO);
}
