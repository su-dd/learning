package com.demo30.case2.app.User;

import com.alibaba.cola.dto.MultiResponse;
import com.alibaba.cola.dto.Response;
import com.alibaba.cola.dto.SingleResponse;
import com.demo30.case2.app.User.executor.command.DeleteUserCmdExe;
import com.demo30.case2.app.User.executor.command.FreshUserCmdExe;
import com.demo30.case2.app.User.executor.command.RegisterUserCmdExe;
import com.demo30.case2.app.User.executor.query.FindUserQryExe;
import com.demo30.case2.app.User.executor.query.FindUsersQryExe;
import com.demo30.case2.client.api.UserService;
import com.demo30.case2.client.dto.clientobject.UserDetailCO;
import com.demo30.case2.client.dto.clientobject.UserSimpleCO;
import com.demo30.case2.client.dto.command.DeleteUserCmd;
import com.demo30.case2.client.dto.command.FreshUserCmd;
import com.demo30.case2.client.dto.command.RegisterUserCmd;
import com.demo30.case2.client.dto.query.FindUserQry;
import com.demo30.case2.client.dto.query.FindUsersQry;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserServiceImpl implements UserService {
    @Autowired
    RegisterUserCmdExe registerUserCmdExe;
    @Autowired
    FindUsersQryExe findUsersQryExe;
    @Autowired
    FindUserQryExe findUserQryExe;
    @Autowired
    FreshUserCmdExe freshUserCmdExe;
    @Autowired
    DeleteUserCmdExe deleteUserCmdExe;

    @Override
    public SingleResponse<UserDetailCO> register(RegisterUserCmd registerUserCmd)  {
        return registerUserCmdExe.execute(registerUserCmd);
    }

    @Override
    public MultiResponse<UserSimpleCO> findList(FindUsersQry findUsersQry) {
        return findUsersQryExe.execute(findUsersQry);
    }

    @Override
    public SingleResponse<UserDetailCO> find(FindUserQry findUserQry) {
        return findUserQryExe.execute(findUserQry);
    }

    @Override
    public SingleResponse<UserDetailCO> setFresh(FreshUserCmd freshUserCmd) {
        return freshUserCmdExe.execute(freshUserCmd);
    }

    @Override
    public Response deleteOne(DeleteUserCmd deleteUserCmd) {
        return deleteUserCmdExe.execute(deleteUserCmd);
    }
}
