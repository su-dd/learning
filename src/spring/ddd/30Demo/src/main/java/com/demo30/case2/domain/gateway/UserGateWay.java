package com.demo30.case2.domain.gateway;

import com.demo30.case2.domain.model.entities.User;
import com.demo30.case2.domain.model.valueobjects.UserId;
import com.demo30.case2.domain.model.valueobjects.UserSearchCondition;

import java.util.List;

public interface UserGateWay {
    User save(User user);
    User update(User user);
    List<User> find(UserSearchCondition userSearchCondition);
    User findById(UserId id);
    void delete(UserId id);
}
