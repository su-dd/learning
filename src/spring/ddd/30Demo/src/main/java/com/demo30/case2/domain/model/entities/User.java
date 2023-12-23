package com.demo30.case2.domain.model.entities;


import com.demo30.case2.domain.gateway.SalesGateWay;
import com.demo30.case2.domain.model.valueobjects.Label;
import com.demo30.case2.domain.model.valueobjects.Name;
import com.demo30.case2.domain.model.valueobjects.PhoneNumber;
import com.demo30.case2.domain.model.valueobjects.RealnameInfo;
import com.demo30.case2.infrastructure.utils.SpringContextUtil;
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
    private SalesGateWay salesGateWay;

    //构造方法
    public User(RealnameInfo info, PhoneNumber phone) throws ValidationException {
        this.name = info.getName();
        this.phone = phone;
        this.label = info.getLabel();

        this.salesGateWay = SpringContextUtil.getBean(SalesGateWay.class);
        this.sales = salesGateWay.find(phone);
    }

    public void fresh() {
        this.fresh = true;
    }
}
