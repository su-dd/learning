package com.demo20.case1.pojo;

import lombok.Data;

import javax.xml.bind.ValidationException;
import java.util.Arrays;

@Data
public class PhoneNumber {
    private final String phone;

    // 区号
    private final String areaCode;

    // 运行商
    private final String OperatorCode;

    public PhoneNumber(String phone) throws ValidationException {
        if (phone == null || !isValidPhoneNumber(phone)) {
            throw new ValidationException("phone");
        }
        this.phone = phone;
        this.areaCode = this.findAreaCode(phone);
        this.OperatorCode = "电信";
    }

    // 获得区号
    public String findAreaCode(String phone) {
        for (int i = 0; i < phone.length(); i++) {
            String prefix = phone.substring(0, i);
            if (isAreaCode(prefix)) {
                return prefix;
            }
        }
        return null;
    }

    public String getOperatorCode() {
        return this.OperatorCode;
    }

    //判断该区号是否存在
    private boolean isAreaCode(String prefix) {
        String[] areas = new String[]{"0571", "021"};
        return Arrays.asList(areas).contains(prefix);
    }

    private boolean isValidPhoneNumber(String phone) {
        String pattern = "^0[1-9]{2,3}-?\\d{8}$";
        return phone.matches(pattern);
    }
}
