package com.demo05.case2.pojo;

import com.demo05.case2.dp.Address;
import com.demo05.case2.dp.Name;
import com.demo05.case2.dp.PhoneNum;
import lombok.Data;

@Data
public class User {
    public Name name;
    public PhoneNum phone;
    public Address address;
    public Long repId;
}
