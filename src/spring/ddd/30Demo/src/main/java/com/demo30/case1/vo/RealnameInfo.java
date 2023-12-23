package com.demo30.case1.vo;

import com.demo30.case1.dto.TelecomInfoDTO;
import lombok.Data;

import javax.xml.bind.ValidationException;

@Data
public class RealnameInfo {
    // 用户名称
    private final Name name;
    // 用户电话
    private final PhoneNumber phoneNumber;
    // 身份ID
    private final String idCard;
    // 标签
    private final Label label;

    public RealnameInfo(Name name, PhoneNumber phoneNumber) throws ValidationException {
        TelecomInfoDTO telecomInfoDTO = getRealnameInfo(phoneNumber);
        // 参数一致性校验
        if (!name.getName().equals(telecomInfoDTO.getName())) {
            throw new ValidationException("phone : " + phoneNumber.getPhone());
        }

        this.name = name;
        this.phoneNumber = phoneNumber;
        this.idCard = telecomInfoDTO.getIdCard();
        this.label = getLabel(telecomInfoDTO);
    }

    // 调用外部rpc
    public TelecomInfoDTO getRealnameInfo(PhoneNumber phoneNumber) {
        return null;
    }

    //计算用户标签
    private Label getLabel(TelecomInfoDTO dto) {
        //本地逻辑处理
        return new Label();
    }
}
