package com.demo30.case1.repository.impl.mapper;

import com.demo30.case1.repository.impl.dateobject.UserDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface UserMapper {
    public UserDO save(UserDO userDO);
    public UserDO insert(UserDO userDO);
}
