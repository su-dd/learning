package com.7Demo.newAnnotation;

public class Information implements com.study.injection.info.Information {
    private String phone;

    public Information(String phone) {
        this.phone = phone;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    @Override
    public String toString() {
        return "Information{" +
                "phone='" + phone + '\'' +
                '}';
    }
}
