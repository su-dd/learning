package com.demo30.case1.repository.impl;


import com.demo30.case1.entity.Sales;
import com.demo30.case1.repository.SalesRepo;
import com.demo30.case1.repository.impl.builder.SalesBuilder;
import com.demo30.case1.repository.impl.dateobject.SalesDO;
import com.demo30.case1.repository.impl.mapper.SalesMapper;
import com.demo30.case1.vo.PhoneNumber;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

@Component
public class SalesRepoImpl implements SalesRepo {
    @Resource
    SalesMapper salesMapper;
    @Override
    public Sales find(PhoneNumber phone) {
        SalesDO salesDO = salesMapper.select(phone.getAreaCode(), phone.getOperatorCode());
        if (salesDO != null) {
            return SalesBuilder.toEntity(salesDO);
        }
        return null;
    }
}
