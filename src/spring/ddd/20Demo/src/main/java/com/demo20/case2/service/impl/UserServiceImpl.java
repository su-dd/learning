package com.demo20.case2.service.impl;

import com.demo20.case2.entity.User;
import com.demo20.case2.repository.UserRepo;
import com.demo20.case2.service.CheckUserService;
import com.demo20.case2.vo.Name;
import com.demo20.case2.vo.PhoneNumber;
import com.demo20.case2.service.UserService;
import com.demo20.case2.service.RealnameService;
import com.demo20.case2.vo.RealnameInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.xml.bind.ValidationException;

@Service
public class UserServiceImpl implements UserService {
    @Autowired
    private UserRepo userRepo;
    @Autowired
    private CheckUserService checkUserService;
    @Autowired
    private RealnameService realnameService;

    @Override
    public User register(Name name, PhoneNumber phone) throws ValidationException {
        // 查询实名信息(实名信息验证)
        RealnameInfo realnameInfo = realnameService.get(name, phone);
        // 构造对象
        User user = new User(realnameInfo, phone);
        // 检查User对象
        checkUserService.check(user);
        return userRepo.save(user);
    }
}
