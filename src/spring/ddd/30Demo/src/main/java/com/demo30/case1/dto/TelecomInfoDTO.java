package com.demo30.case1.dto;

import lombok.Data;

import java.io.Serializable;

@Data
public class TelecomInfoDTO implements Serializable {
    // 姓名
    private String name;
    // 身份证
    private String idCard;
    // 手机号
    private String phoneNum;
}
