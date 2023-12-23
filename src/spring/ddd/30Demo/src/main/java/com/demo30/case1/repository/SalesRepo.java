package com.demo30.case1.repository;

import com.demo30.case2.domain.model.entities.Sales;
import com.demo30.case2.domain.model.valueobjects.PhoneNumber;

public interface SalesRepo {
    Sales find(PhoneNumber phone);
}
