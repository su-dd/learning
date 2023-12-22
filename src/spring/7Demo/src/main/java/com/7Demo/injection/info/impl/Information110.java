package com.7Demo.injection.info.impl;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

@Service("information110")
public class Information110 implements Information {
    private String phone;

    public String getPhone() {
        return phone;
    }

    @Value("110")
    public void setPhone(String phone) {
        this.phone = phone;
    }

    @Override
    public String toString() {
        return "Information110{" +
                "phone='" + phone + '\'' +
                '}';
    }
}
