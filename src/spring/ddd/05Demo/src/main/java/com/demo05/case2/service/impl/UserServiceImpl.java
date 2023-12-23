package com.demo05.case2.service.impl;

import com.demo05.case2.dp.Address;
import com.demo05.case2.dp.Name;
import com.demo05.case2.dp.PhoneNum;
import com.demo05.case2.pojo.SalesRep;
import com.demo05.case2.pojo.User;
import com.demo05.case2.repository.SalesRepRepo;
import com.demo05.case2.repository.UserRepo;
import com.demo05.case2.service.UserService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Service
public class UserServiceImpl implements UserService {
    @Resource
    private UserRepo userRepo;
    @Resource
    private SalesRepRepo salesRepRepo;

    @Override
    public User register(Name name, PhoneNum phone, Address address) {
        //找到区号负责人（SalesRep）
        SalesRep rep = salesRepRepo.findRep(phone.findAreaCode());

        // 最后创建用户，落盘，然后返回
        User user = new User();
        user.name = name;
        user.phone = phone;
        user.address = address;
        if (null != rep) {
            user.repId = rep.id;
        }

        return userRepo.save(user);
    }
}
