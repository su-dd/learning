package com.demo30.case2.infrastructure.gatewayimpl;

import com.demo30.case2.domain.gateway.UserGateWay;
import com.demo30.case2.domain.model.entities.User;
import com.demo30.case2.domain.model.valueobjects.UserId;
import com.demo30.case2.domain.model.valueobjects.UserSearchCondition;
import com.demo30.case2.infrastructure.convertor.UserBuilder;
import com.demo30.case2.infrastructure.gatewayimpl.database.dataobject.UserDO;
import com.demo30.case2.infrastructure.gatewayimpl.database.mapper.UserMapper;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.util.List;

@Component
public class UserGateWayImpl implements UserGateWay {
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
    public List<User> find(UserSearchCondition userSearchCondition) {
        return null;
    }

    @Override
    public User findById(UserId id) {
        return null;
    }

    @Override
    public void delete(UserId id) {
        return false;
    }
}
