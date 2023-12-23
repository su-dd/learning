package com.demo30.case1.repository.impl;


import com.demo30.case1.dto.UserParamDTO;
import com.demo30.case1.entity.User;
import com.demo30.case1.repository.UserRepo;
import com.demo30.case1.repository.impl.builder.UserBuilder;
import com.demo30.case1.repository.impl.dateobject.UserDO;
import com.demo30.case1.repository.impl.mapper.UserMapper;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.util.List;

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

    @Override
    public User update(User user) {
        return null;
    }

    @Override
    public List<User> find(UserParamDTO userParamDTO) {
        return null;
    }

    @Override
    public User findById(String id) {
        return null;
    }

    @Override
    public boolean delete(String id) {
        return false;
    }
}
