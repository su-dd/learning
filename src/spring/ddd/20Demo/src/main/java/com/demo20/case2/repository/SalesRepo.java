package com.demo20.case2.repository;

import com.demo20.case2.entity.Sales;
import com.demo20.case2.vo.PhoneNumber;

public interface SalesRepo {
    Sales find(PhoneNumber phone);
}
