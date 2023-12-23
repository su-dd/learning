package com.demo05.case2.dp;

import javax.xml.bind.ValidationException;
import java.util.Arrays;

public class PhoneNum {
    private final String phone;

    public PhoneNum(String phone) throws ValidationException {
        if (phone == null || !isValidPhoneNumber(phone)) {
            throw new ValidationException("phone");
        }
        this.phone = phone;
    }

    public String findAreaCode() {
        for (int i = 0; i < phone.length(); i++) {
            String prefix = phone.substring(0, i);
            if (isAreaCode(prefix)) {
                return prefix;
            }
        }
        return null;
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
