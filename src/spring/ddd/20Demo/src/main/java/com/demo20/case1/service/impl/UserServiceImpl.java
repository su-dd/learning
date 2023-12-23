package com.demo20.case1.service.impl;

import com.demo20.case1.pojo.Name;
import com.demo20.case1.pojo.PhoneNumber;
import com.demo20.case1.pojo.RewardDO;
import com.demo20.case1.pojo.SalesDO;
import com.demo20.case1.pojo.TelecomInfoDTO;
import com.demo20.case1.pojo.UserDO;
import com.demo20.case1.repository.RewardMapper;
import com.demo20.case1.repository.SalesMapper;
import com.demo20.case1.repository.UserMapper;
import com.demo20.case1.service.UserService;
import com.demo20.case1.service.RiskControlService;
import com.demo20.case1.service.TelecomRealnameService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import javax.xml.bind.ValidationException;

@Service
public class UserServiceImpl implements UserService {
    @Resource
    private UserMapper userMapper;
    @Resource
    private SalesMapper salesMapper;
    @Resource
    private RewardMapper rewardMapper;
    @Autowired
    private TelecomRealnameService telecomRealnameService;
    @Autowired
    private RiskControlService riskControlService;

    @Override
    public UserDO register(Name name, PhoneNumber phone) throws ValidationException {
        //参数合法性校验已在PhoneNumber中处理
        //参数一致性校验
        TelecomInfoDTO telecomInfoDTO = telecomRealnameService.getRealnameInfo(phone.getPhone());
        if (!name.getName().equals(telecomInfoDTO.getName())) {
            throw new ValidationException("phone : " + phone.getPhone());
        }
        //计算用户标签
        String label = getLabel(telecomInfoDTO);
        //计算销售ID
        String salesId = getSalesId(phone);
        //返回身份证
        String idCard = telecomInfoDTO.getIdCard();
        // 用户
        UserDO userDO = new UserDO(idCard, name.getName(), phone.getPhone(), label, salesId);
        // 对应新客奖励
        RewardDO rewardDO = new RewardDO(idCard,label);
        // 检查风控（查看库存等）
        if(!riskControlService.check(idCard, label)) {
            userDO.setNew(true);
            rewardDO.setAvailable(false);
        } else {
            userDO.setNew(false);
            rewardDO.setAvailable(true) ;
        }
        //存储信息
        rewardMapper.insert(rewardDO) ;
        return userMapper.insert(userDO);
    }

    // 根据电信返回信息，计算用户标签
    private String getLabel(TelecomInfoDTO dto){
        //本地逻辑处理
        return "";
    }

    // 根据电话信息，获得销售ID
    private String getSalesId(PhoneNumber phone) {
        SalesDO salesDO = salesMapper.select(phone.getAreaCode(), phone.getOperatorCode());
        if (salesDO != null){
            return salesDO.getSalesId();
        }
        return null;
    }
}
