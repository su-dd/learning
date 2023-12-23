package com.demo30.case2.domain.gateway;

import com.demo30.case2.domain.model.entities.Sales;
import com.demo30.case2.domain.model.valueobjects.PhoneNumber;

public interface SalesGateWay {
    Sales find(PhoneNumber phone);
}
