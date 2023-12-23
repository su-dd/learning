package com.demo30.case2.client.dto.query;

import com.alibaba.cola.dto.Query;
import lombok.Data;

@Data
public class FindUsersQry extends Query {
    // 用户名称
    private String name;
    // 用户手机
    private String phone;
    //绑定销售id
    private String salesId;
}
