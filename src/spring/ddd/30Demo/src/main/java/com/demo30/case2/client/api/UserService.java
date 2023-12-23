package com.demo30.case2.client.api;

import com.alibaba.cola.dto.MultiResponse;
import com.alibaba.cola.dto.Response;
import com.alibaba.cola.dto.SingleResponse;
import com.demo30.case2.client.dto.clientobject.UserDetailCO;
import com.demo30.case2.client.dto.clientobject.UserSimpleCO;
import com.demo30.case2.client.dto.command.DeleteUserCmd;
import com.demo30.case2.client.dto.command.FreshUserCmd;
import com.demo30.case2.client.dto.command.RegisterUserCmd;
import com.demo30.case2.client.dto.query.FindUserQry;
import com.demo30.case2.client.dto.query.FindUsersQry;

public interface UserService {
    SingleResponse<UserDetailCO> register(RegisterUserCmd registerUserCmd);
    MultiResponse<UserSimpleCO> findList(FindUsersQry FindUsersQry);
    SingleResponse<UserDetailCO> find(FindUserQry findUserQry);
    SingleResponse<UserDetailCO> setFresh(FreshUserCmd freshUserCmd);
    Response deleteOne(DeleteUserCmd deleteUserCmd);
}
