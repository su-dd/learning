package com.demo30.case2.domain.ability.impl;


import com.demo30.case2.domain.ability.CheckUserService;
import com.demo30.case2.domain.ability.RiskControlService;
import com.demo30.case2.domain.gateway.RewardGateWay;
import com.demo30.case2.domain.model.entities.Reward;
import com.demo30.case2.domain.model.entities.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class CheckUserServiceImpl implements CheckUserService {
    @Autowired
    private RewardGateWay rewardRepo;
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
