package com.demo20.case1.repository;

import com.demo20.case1.pojo.SalesDO;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface SalesMapper {
    SalesDO select(String areaCode, String operatorCode);
}
