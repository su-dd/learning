package com.demo20.case2.vo;

import lombok.Data;

import javax.xml.bind.ValidationException;

@Data
public class Name {
    private final String name;

    public Name(String name) throws ValidationException {
        // 校验逻辑
        if (name == null || name.length() == 0) {
            throw new ValidationException("name");
        }
        this.name = name;
    }
}
