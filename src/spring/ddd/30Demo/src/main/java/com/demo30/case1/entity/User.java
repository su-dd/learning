package com.demo30.case1.entity;

import com.demo30.case1.entity.Sales;
import com.demo30.case1.repository.SalesRepo;
import com.demo30.case1.utils.SpringContextUtil;
import com.demo30.case1.vo.*;
import lombok.Data;

import javax.xml.bind.ValidationException;

@Data
public class User {
    // 用户id
    private String userId;
    // 用户名称
    private Name name;
    // 用户手机，DP
    private PhoneNumber phone;
    //用户标签，DP
    private Label label;
    //绑定销售id,DP
    private Sales sales;
    // 标志是否为新用户，默认为false
    private Boolean fresh = false;

    // 销售查询接口
    private SalesRepo salesRepo;

    //构造方法
    public User(RealnameInfo info, PhoneNumber phone) throws ValidationException {
        this.name = info.getName();
        this.phone = phone;
        this.label = info.getLabel();

        this.salesRepo = SpringContextUtil.getBean(SalesRepo.class);
        this.sales = salesRepo.find(phone);
    }

    public void fresh() {
        this.fresh = true;
    }
}
