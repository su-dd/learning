package com.demo20.case2.repository.impl.mapper;

import com.demo20.case2.repository.impl.dateobject.SalesDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface SalesMapper {
    SalesDO findRep(String areaCode);
    SalesDO select(String areaCode, String operatorCode);
}
