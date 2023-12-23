package com.demo20.case2.controller;

import com.demo20.case2.entity.User;
import com.demo20.case2.vo.Name;
import com.demo20.case2.vo.PhoneNumber;
import com.demo20.case2.service.UserService;
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
    public User register(@RequestParam String name, @RequestParam String phone) throws ValidationException {
        return userService.register(new Name(name), new PhoneNumber(phone));
    }
}
