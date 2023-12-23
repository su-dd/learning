package com.demo30.case2.infrastructure.gatewayimpl.database.mapper;

import com.demo30.case2.infrastructure.gatewayimpl.database.dataobject.SalesDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface SalesMapper {
    SalesDO findRep(String areaCode);
    SalesDO select(String areaCode, String operatorCode);
}
