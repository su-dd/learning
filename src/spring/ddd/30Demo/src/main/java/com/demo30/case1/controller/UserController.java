package com.demo30.case1.controller;

import com.demo30.case1.dto.UserParamDTO;
import com.demo30.case1.dto.UserDTO;
import com.demo30.case1.vo.Name;
import com.demo30.case1.vo.PhoneNumber;
import com.demo30.case1.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import javax.xml.bind.ValidationException;
import java.util.List;

@Controller
@RequestMapping(value = "/case1")
public class UserController {
    @Autowired
    UserService userService;

    @RequestMapping(value = "/register", method = RequestMethod.POST)
    @ResponseBody
    public UserDTO register(@RequestBody UserParamDTO userParamDTO) throws ValidationException {
        return userService.register(new Name(userParamDTO.getName()), new PhoneNumber(userParamDTO.getPhone()));
    }

    @RequestMapping(value = "/findList", method = RequestMethod.POST)
    @ResponseBody
    public List<UserDTO> findList(@RequestBody UserParamDTO userParamDTO) {
        return userService.findList(userParamDTO);
    }

    @RequestMapping(value = "/findOne", method = RequestMethod.POST)
    @ResponseBody
    public UserDTO find(@RequestBody UserParamDTO userParamDTO){
        return userService.find(userParamDTO);
    }

    @RequestMapping(value = "/setFresh", method = RequestMethod.POST)
    @ResponseBody
    public UserDTO setFresh(@RequestBody UserParamDTO userParamDTO) {
        return userService.setFresh(userParamDTO);
    }

    @RequestMapping(value = "/deleteOne", method = RequestMethod.POST)
    @ResponseBody
    public Boolean deleteOne(@RequestBody UserParamDTO userParamDTO) {
        return userService.deleteOne(userParamDTO);
    }

}
