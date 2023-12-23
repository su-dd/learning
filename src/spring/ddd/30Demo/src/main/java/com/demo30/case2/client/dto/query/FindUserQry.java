package com.demo30.case2.client.dto.query;

import com.alibaba.cola.dto.Query;
import lombok.Data;

@Data
public class FindUserQry extends Query {
    // 用户id
    private String userId;
}
