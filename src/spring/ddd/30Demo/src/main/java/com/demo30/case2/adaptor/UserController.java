package com.demo30.case2.adaptor;

import com.alibaba.cola.dto.MultiResponse;
import com.alibaba.cola.dto.Response;
import com.alibaba.cola.dto.SingleResponse;
import com.demo30.case2.client.api.UserService;
import com.demo30.case2.client.dto.clientobject.UserDetailCO;
import com.demo30.case2.client.dto.clientobject.UserSimpleCO;
import com.demo30.case2.client.dto.command.DeleteUserCmd;
import com.demo30.case2.client.dto.command.FreshUserCmd;
import com.demo30.case2.client.dto.command.RegisterUserCmd;
import com.demo30.case2.client.dto.query.FindUserQry;
import com.demo30.case2.client.dto.query.FindUsersQry;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

@Controller
@RequestMapping(value = "/case2")
public class UserController {
    @Autowired
    UserService userService;

    @RequestMapping(value = "/register", method = RequestMethod.POST)
    @ResponseBody
    public SingleResponse<UserDetailCO> register(@RequestBody RegisterUserCmd registerUserCmd) {
        return userService.register(registerUserCmd);
    }

    @RequestMapping(value = "/findList", method = RequestMethod.POST)
    @ResponseBody
    public MultiResponse<UserSimpleCO> findList(@RequestBody FindUsersQry FindUsersQry) {
        return userService.findList(FindUsersQry);
    }

    @RequestMapping(value = "/findOne", method = RequestMethod.POST)
    @ResponseBody
    public SingleResponse<UserDetailCO> find(@RequestBody FindUserQry findUserQry){
        return userService.find(findUserQry);
    }

    @RequestMapping(value = "/setFresh", method = RequestMethod.POST)
    @ResponseBody
    public SingleResponse<UserDetailCO> setFresh(@RequestBody FreshUserCmd freshUserCmd) {
        return userService.setFresh(freshUserCmd);
    }

    @RequestMapping(value = "/deleteOne", method = RequestMethod.POST)
    @ResponseBody
    public Response deleteOne(@RequestBody DeleteUserCmd deleteUserCmd) {
        return userService.deleteOne(deleteUserCmd);
    }

}
