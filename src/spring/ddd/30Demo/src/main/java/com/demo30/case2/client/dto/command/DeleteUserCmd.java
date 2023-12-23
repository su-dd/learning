package com.demo30.case2.client.dto.command;

import com.alibaba.cola.dto.Command;
import lombok.Data;

@Data
public class DeleteUserCmd extends Command {
    // 用户id
    private String userId;
}
