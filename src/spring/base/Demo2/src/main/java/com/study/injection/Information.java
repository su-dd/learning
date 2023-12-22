package com.study.injection;

public class Information {
    private String phoneNum;

    public Information(String phoneNum) {
        this.phoneNum = phoneNum;
    }

    public String getPhoneNum() {
        return phoneNum;
    }

    public void setPhoneNum(String phoneNum) {
        this.phoneNum = phoneNum;
    }

    @Override
    public String toString() {
        return "Information{" +
                "phoneNum='" + phoneNum + '\'' +
                '}';
    }
}
