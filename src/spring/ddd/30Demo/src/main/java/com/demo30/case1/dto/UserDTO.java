package com.demo30.case1.dto;

import com.demo30.case1.entity.User;
import lombok.Data;

import java.io.Serializable;

@Data
public class UserDTO implements Serializable {
    // 用户id
    private String userId;
    // 用户名称
    private String name;
    // 用户手机
    private String phone;
    //用户标签
    private String label;
    //绑定销售id
    private String salesId;
    // 标志是否为新用户，默认为false
    private Boolean fresh;

    public UserDTO(String userId, String name, String phone, String label, String salesId, Boolean fresh) {
        this.userId = userId;
        this.name = name;
        this.phone = phone;
        this.label = label;
        this.salesId = salesId;
        this.fresh = fresh;
    }

    public UserDTO(User user) {
        this.userId = user.getUserId();
        this.name = user.getName().getName();
        this.phone = user.getPhone().getPhone();
        this.label = user.getLabel().toString();
        this.salesId = user.getSales().getSalesId();
        this.fresh = user.getFresh();
    }
}
