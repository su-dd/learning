package com.demo20.case2.repository.impl.mapper;

import com.demo20.case2.repository.impl.dateobject.UserDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface UserMapper {
    public UserDO save(UserDO userDO);
    public UserDO insert(UserDO userDO);
}
