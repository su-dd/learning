package com.demo30.case2.app.User.executor.command;

import com.alibaba.cola.dto.SingleResponse;
import com.demo30.case2.client.dto.clientobject.UserDetailCO;
import com.demo30.case2.client.dto.command.RegisterUserCmd;
import com.demo30.case2.domain.ability.CheckUserService;
import com.demo30.case2.domain.ability.RealnameService;
import com.demo30.case2.domain.gateway.UserGateWay;
import com.demo30.case2.domain.model.entities.User;
import com.demo30.case2.domain.model.valueobjects.Name;
import com.demo30.case2.domain.model.valueobjects.PhoneNumber;
import com.demo30.case2.domain.model.valueobjects.RealnameInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.xml.bind.ValidationException;

@Component
public class RegisterUserCmdExe {
    @Autowired
    private UserGateWay userGateWay;
    @Autowired
    private CheckUserService checkUserService;
    @Autowired
    private RealnameService realnameService;

    public SingleResponse<UserDetailCO> execute(RegisterUserCmd registerUserCmd) {
        try {
            // 查询实名信息(实名信息验证)
            RealnameInfo realnameInfo = realnameService.get(new Name(registerUserCmd.getName()), new PhoneNumber(registerUserCmd.getPhone()));
            // 构造对象
            User user = new User(realnameInfo, new PhoneNumber(registerUserCmd.getPhone()));
            // 检查User对象
            checkUserService.check(user);
            return SingleResponse.of(new UserDetailCO(userGateWay.save(user)));
        } catch (ValidationException e) {
            e.printStackTrace();
            return SingleResponse.buildFailure("401", e.getMessage());
        }
    }
}
