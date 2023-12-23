package com.demo30.case1.dto;

import lombok.Data;

import java.io.Serializable;

@Data
public class UserParamDTO implements Serializable {
    // 用户id
    private String userId;
    // 用户名称
    private String name;
    // 用户手机
    private String phone;
    //绑定销售id
    private String salesId;
    // 标志是否为新用户，默认为false
    private Boolean fresh;
}
