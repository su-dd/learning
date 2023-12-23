package com.demo05.case1.service.impl;

import com.demo05.case1.pojo.SalesRep;
import com.demo05.case1.pojo.User;
import com.demo05.case1.repository.SalesRepRepo;
import com.demo05.case1.service.UserService;
import com.demo05.case1.repository.UserRepo;
import org.springframework.stereotype.Service;

import javax.xml.bind.ValidationException;
import java.util.Arrays;

@Service
public class UserServiceImpl implements UserService {
    private UserRepo userRepo;
    private SalesRepRepo salesRepRepo;

    @Override
    public User register(String name, String phone, String address) throws ValidationException {
        // 校验逻辑
        if (name == null || name.length() == 0) {
            throw new ValidationException("name");
        }
        if (phone == null || !isValidPhoneNumber(phone)) {
            throw new ValidationException("phone");
        }
        // 此处省略address的校验逻辑s

        // 取电话号里的区号，然后通过区号找到区域内的SalesRep
        String areaCode = null;
        String[] areas = new String[]{"0571", "021", "010"};
        for (int i = 0; i < phone.length(); i++) {
            String prefix = phone.substring(0, i);
            if (Arrays.asList(areas).contains(prefix)) {
                areaCode = prefix;
                break;
            }
        }
        //找到区号负责人（SalesRep）
        SalesRep rep = salesRepRepo.findRep(areaCode);
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

    private boolean isValidPhoneNumber(String phone) {
        String pattern = "^0[1-9]{2,3}-?\\d{8}$";
        return phone.matches(pattern);
    }
}
