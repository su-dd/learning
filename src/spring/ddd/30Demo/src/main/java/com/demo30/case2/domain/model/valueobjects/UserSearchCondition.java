package com.demo30.case2.domain.model.valueobjects;

import lombok.Data;

import javax.xml.bind.ValidationException;

@Data
public class UserSearchCondition {
    // 用户名称
    private String name;
    // 用户手机
    private String phone;
    //绑定销售id
    private String salesId;

    public UserSearchCondition(String name, String phone, String salesId) throws ValidationException {
        if (phone != null && !isValidPhoneNumber(phone)) {
            throw new ValidationException("phone 不符合格式");
        }
        this.name = name;
        this.phone = phone;
        this.salesId = salesId;
    }

    private boolean isValidPhoneNumber(String phone) {
        String pattern = "^0[1-9]{2,3}-?\\d{8}$";
        return phone.matches(pattern);
    }
}
