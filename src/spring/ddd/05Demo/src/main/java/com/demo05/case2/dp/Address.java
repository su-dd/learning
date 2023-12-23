package com.demo05.case2.dp;

import lombok.Data;

import javax.xml.bind.ValidationException;

@Data
public class Address {
    private final String country;
    private final String province;
    private final String city;
    private final String detailed;

    public Address(String address) throws ValidationException {
        // 解析 校验 address 做赋值
        this.country = analyzeCountry(address);
        if (this.country  == null || this.country .length() == 0) {
            throw new ValidationException("country");
        }
        this.city = analyzeCity(address);
        if (this.city  == null || this.city .length() == 0) {
            throw new ValidationException("city");
        }
        this.province = analyzeProvince(address);
        if (this.province  == null || this.province .length() == 0) {
            throw new ValidationException("province");
        }
        this.detailed = analyzeDetailed(address);
        if (this.detailed  == null || this.detailed .length() == 0) {
            throw new ValidationException("detailed");
        }
    }

    private String analyzeCountry(String address) {
        return null;
    }

    private String analyzeProvince(String address) {
        return null;
    }

    private String analyzeCity(String address) {
        return null;
    }

    private String analyzeDetailed(String address) {
        return null;
    }
}
