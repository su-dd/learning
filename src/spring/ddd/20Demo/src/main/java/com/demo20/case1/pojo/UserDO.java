package com.demo20.case1.pojo;

import lombok.Data;

@Data
public class UserDO {
    private String userId;
    private String idCard;
    private String name;
    private String phone;
    private String label;
    private String salesId;
    private boolean isNew;

    public UserDO(String idCard, String name, String phone, String label, String salesId) {
        this.idCard = idCard;
        this.name = name;
        this.phone = phone;
        this.label = label;
        this.salesId = salesId;
    }

}
