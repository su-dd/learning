package com.demo20.case2.service.impl;

import com.demo20.case2.entity.Reward;
import com.demo20.case2.entity.User;
import com.demo20.case2.repository.RewardRepo;
import com.demo20.case2.service.CheckUserService;
import com.demo20.case2.service.RealnameService;
import com.demo20.case2.service.RiskControlService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class CheckUserServiceImpl implements CheckUserService {
    @Autowired
    private RewardRepo rewardRepo;
    @Autowired
    private RiskControlService riskControlService;

    @Override
    public void check(User user) {
        // 新手赠品检查
        this.rewardCheck(user);

        // 其他检查
    }

    private void rewardCheck(User user) {
        Reward reward = new Reward(user);
        //检查风控
        if (!riskControlService.check(user)) {
            user.fresh();
            reward.inavailable();
        }
        rewardRepo.save(reward);
    }
}
