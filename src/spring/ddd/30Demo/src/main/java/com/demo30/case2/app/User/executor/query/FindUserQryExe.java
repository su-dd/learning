package com.demo30.case2.app.User.executor.query;

import com.alibaba.cola.dto.SingleResponse;
import com.demo30.case2.client.dto.clientobject.UserDetailCO;
import com.demo30.case2.client.dto.query.FindUserQry;
import com.demo30.case2.domain.gateway.UserGateWay;
import com.demo30.case2.domain.model.entities.User;
import com.demo30.case2.domain.model.valueobjects.UserId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.xml.bind.ValidationException;

@Component
public class FindUserQryExe {
    @Autowired
    private UserGateWay userGateWay;

    public SingleResponse<UserDetailCO> execute(FindUserQry findUserQry) {
        try {
            User user = userGateWay.findById(new UserId(findUserQry.getUserId()));
            if (null != user) {
                return SingleResponse.of(new UserDetailCO(user));
            }
            return SingleResponse.buildFailure("400", "无对应用户");
        } catch (ValidationException e) {
            e.printStackTrace();
            return SingleResponse.buildFailure("401", e.getMessage());
        }
    }
}
