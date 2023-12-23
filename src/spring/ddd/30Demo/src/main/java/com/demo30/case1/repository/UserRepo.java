package com.demo30.case1.repository;

import com.demo30.case1.dto.UserParamDTO;
import com.demo30.case1.entity.User;

import java.util.List;

public interface UserRepo {
    User save(User user);
    User update(User user);
    List<User> find(UserParamDTO userParamDTO);
    User findById(String id);
    boolean delete(String id);
}
