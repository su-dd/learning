package com.demo30.case2.domain.model.entities;

import lombok.Data;

@Data
public class Reward {
    private String rewardId;
    private User user;
    // 标志 新手福利是否可获得，默认为true
    private Boolean available = true;

    public Reward(User user) {
        this.user = user;
    }

    public void inavailable() {
        this.available = false;
    }
}
