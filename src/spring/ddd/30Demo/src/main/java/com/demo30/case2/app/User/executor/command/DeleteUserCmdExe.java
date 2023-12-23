package com.demo30.case2.app.User.executor.command;

import com.alibaba.cola.dto.Response;
import com.demo30.case2.client.dto.command.DeleteUserCmd;
import com.demo30.case2.domain.gateway.UserGateWay;
import com.demo30.case2.domain.model.valueobjects.UserId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.xml.bind.ValidationException;

@Component
public class DeleteUserCmdExe {
    @Autowired
    private UserGateWay userGateWay;

    public Response execute(DeleteUserCmd deleteUserCmd) {
        try {
             userGateWay.delete(new UserId(deleteUserCmd.getUserId()));
             return Response.buildSuccess();
        } catch (ValidationException e) {
            e.printStackTrace();
            return Response.buildFailure("401", e.getMessage());
        }
    }
}
