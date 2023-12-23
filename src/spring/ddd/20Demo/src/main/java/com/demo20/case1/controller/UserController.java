package com.demo20.case1.controller;

import com.demo20.case1.pojo.Name;
import com.demo20.case1.pojo.PhoneNumber;
import com.demo20.case1.pojo.UserDO;
import com.demo20.case1.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.xml.bind.ValidationException;

@Controller
@RequestMapping(value = "/case1")
public class UserController {
    @Autowired
    UserService userService;

    @RequestMapping(value = "/register", method = RequestMethod.POST)
    @ResponseBody
    public UserDO register(@RequestParam String name, @RequestParam String phone, @RequestParam String address) throws ValidationException {
        return userService.register(new Name(name), new PhoneNumber(phone));
    }
}
