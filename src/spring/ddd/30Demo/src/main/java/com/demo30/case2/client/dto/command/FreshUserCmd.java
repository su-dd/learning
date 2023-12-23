package com.demo30.case2.client.dto.command;

import com.alibaba.cola.dto.Command;
import lombok.Data;

@Data
public class FreshUserCmd extends Command {
    // 用户id
    private String userId;
    // 标志是否为新用户，默认为false
    private Boolean fresh;
}
