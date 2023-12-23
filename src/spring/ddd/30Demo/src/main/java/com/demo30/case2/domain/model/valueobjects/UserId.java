package com.demo30.case2.domain.model.valueobjects;

import lombok.Data;

import javax.xml.bind.ValidationException;

@Data
public class UserId {
    public UserId(String userId) throws ValidationException {
        if (null == userId || userId.length() == 0) {
            throw new ValidationException("userId");
        }
        this.userId = userId;
    }

    // 用户id
    private String userId;
}
