package com.demo30.case2.app.User.executor.command;

import com.alibaba.cola.dto.SingleResponse;
import com.demo30.case2.client.dto.clientobject.UserDetailCO;
import com.demo30.case2.client.dto.command.FreshUserCmd;
import com.demo30.case2.domain.ability.CheckUserService;
import com.demo30.case2.domain.ability.RealnameService;
import com.demo30.case2.domain.gateway.UserGateWay;
import com.demo30.case2.domain.model.entities.User;
import com.demo30.case2.domain.model.valueobjects.UserId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.xml.bind.ValidationException;

@Component
public class FreshUserCmdExe {
    @Autowired
    private UserGateWay userGateWay;
    @Autowired
    private CheckUserService checkUserService;
    @Autowired
    private RealnameService realnameService;

    public SingleResponse<UserDetailCO> execute(FreshUserCmd freshUserCmd) {
        try {
            User user = userGateWay.findById(new UserId(freshUserCmd.getUserId()));
            if (null != user) {
                // 设置用户为新客身份，以便发送新手礼包
                user.setFresh(true);
                // 检查User对象
                checkUserService.check(user);
                return SingleResponse.of(new UserDetailCO(user));
            }
            return SingleResponse.buildFailure("400", "找不到对应用户");
        } catch (ValidationException e) {
            e.printStackTrace();
            return SingleResponse.buildFailure("401", e.getMessage());
        }
    }
}
