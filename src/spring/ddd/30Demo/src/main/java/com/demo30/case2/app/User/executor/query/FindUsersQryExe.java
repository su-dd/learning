package com.demo30.case2.app.User.executor.query;

import com.alibaba.cola.dto.MultiResponse;
import com.demo30.case2.client.dto.clientobject.UserSimpleCO;
import com.demo30.case2.client.dto.query.FindUsersQry;
import com.demo30.case2.domain.gateway.UserGateWay;
import com.demo30.case2.domain.model.entities.User;
import com.demo30.case2.domain.model.valueobjects.UserSearchCondition;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.xml.bind.ValidationException;
import java.util.ArrayList;
import java.util.List;

@Component
public class FindUsersQryExe {
    @Autowired
    private UserGateWay userGateWay;

    public MultiResponse<UserSimpleCO> execute(FindUsersQry findUsersQry) {
        try {
            List<User> userList = userGateWay.find(
                    new UserSearchCondition(findUsersQry.getName(), findUsersQry.getPhone(), findUsersQry.getSalesId()));

            List<UserSimpleCO> userSimpleCOList = new ArrayList<>();
            userList.forEach(user -> {
                userSimpleCOList.add(new UserSimpleCO(user));
            });
            return MultiResponse.of(userSimpleCOList);

        } catch (ValidationException e) {
            e.printStackTrace();
            return MultiResponse.buildFailure("401", e.getMessage());
        }
    }
}
