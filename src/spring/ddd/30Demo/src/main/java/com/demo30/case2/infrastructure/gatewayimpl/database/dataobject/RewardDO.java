package com.demo30.case2.infrastructure.gatewayimpl.database.dataobject;

import lombok.Data;

@Data
public class RewardDO {
    private String idCard;
    private String label;
    private boolean available;

    public RewardDO(String idCard, String label) {
        this.idCard = idCard;
        this.label = label;
    }
}
