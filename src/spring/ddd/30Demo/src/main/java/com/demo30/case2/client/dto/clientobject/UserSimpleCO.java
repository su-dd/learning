package com.demo30.case2.client.dto.clientobject;

import com.demo30.case2.domain.model.entities.User;
import lombok.Data;

import java.io.Serializable;

@Data
public class UserSimpleCO implements Serializable {
    // 用户id
    private String userId;
    // 用户名称
    private String name;
    // 用户手机
    private String phone;
    // 标志是否为新用户，默认为false
    private Boolean fresh;

    public UserSimpleCO(User user) {
        this.userId = user.getUserId();
        this.name = user.getName().getName();
        this.phone = user.getPhone().getPhone();
        this.fresh = user.getFresh();
    }
}
