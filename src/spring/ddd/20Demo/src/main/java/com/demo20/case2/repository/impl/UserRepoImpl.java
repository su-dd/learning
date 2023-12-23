package com.demo20.case2.repository.impl;


import com.demo20.case2.entity.User;
import com.demo20.case2.repository.UserRepo;
import com.demo20.case2.repository.impl.builder.UserBuilder;
import com.demo20.case2.repository.impl.dateobject.UserDO;
import com.demo20.case2.repository.impl.mapper.UserMapper;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

@Component
public class UserRepoImpl implements UserRepo {
    @Resource
    UserMapper userMapper;
    @Override
    public User save(User user) {
        UserDO userDO = UserBuilder.toDO(user);
        userMapper.save(userDO);
        return UserBuilder.toEntity(userDO);
    }
}
