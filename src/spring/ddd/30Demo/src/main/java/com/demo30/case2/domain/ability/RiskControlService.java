package com.demo30.case2.domain.ability;

import com.demo30.case2.domain.model.entities.User;

public interface RiskControlService {
    boolean check(User user);
}
