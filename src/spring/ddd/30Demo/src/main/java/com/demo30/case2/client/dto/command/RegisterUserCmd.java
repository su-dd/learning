package com.demo30.case2.client.dto.command;

import com.alibaba.cola.dto.Command;
import lombok.Data;

@Data
public class RegisterUserCmd extends Command {
    // 用户名称
    private String name;
    // 用户手机
    private String phone;
}
