package com.demo05.case2.controller;

import com.demo05.case2.dp.Address;
import com.demo05.case2.dp.Name;
import com.demo05.case2.dp.PhoneNum;
import com.demo05.case2.pojo.User;
import com.demo05.case2.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.xml.bind.ValidationException;

@Controller
@RequestMapping(value = "/case2")
public class UserController {
    @Autowired
    UserService userService;

    @RequestMapping(value = "/register", method = RequestMethod.POST)
    @ResponseBody
    public User register(@RequestParam String name, @RequestParam String phone, @RequestParam String address) throws ValidationException {
        return userService.register(new Name(name), new PhoneNum(phone), new Address(address));
    }
}
