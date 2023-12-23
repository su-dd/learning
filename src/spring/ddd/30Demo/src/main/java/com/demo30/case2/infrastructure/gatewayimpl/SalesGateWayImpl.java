package com.demo30.case2.infrastructure.gatewayimpl;

import com.demo30.case2.domain.gateway.SalesGateWay;
import com.demo30.case2.domain.model.entities.Sales;
import com.demo30.case2.domain.model.valueobjects.PhoneNumber;
import com.demo30.case2.infrastructure.convertor.SalesBuilder;
import com.demo30.case2.infrastructure.gatewayimpl.database.dataobject.SalesDO;
import com.demo30.case2.infrastructure.gatewayimpl.database.mapper.SalesMapper;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;

@Component
public class SalesGateWayImpl implements SalesGateWay {
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
