package com.demo30.case1.service.impl;


import com.demo30.case1.entity.Reward;
import com.demo30.case1.entity.User;
import com.demo30.case1.repository.RewardRepo;
import com.demo30.case1.service.CheckUserService;
import com.demo30.case1.service.RiskControlService;
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
        } else {
            user.setFresh(false);
            reward.setAvailable(true);
        }
        rewardRepo.save(reward);
    }
}
