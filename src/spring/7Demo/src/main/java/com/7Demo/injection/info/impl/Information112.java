package com.7Demo.injection.info.impl;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

@Service("information112")
public class Information112 implements Information {
    @Value("112")
    private String phone;

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    @Override
    public String toString() {
        return "Information112{" +
                "phone='" + phone + '\'' +
                '}';
    }
}
