package com.demo30.case1.service.impl;

import com.demo30.case1.dto.UserDTO;
import com.demo30.case1.dto.UserParamDTO;
import com.demo30.case1.entity.User;
import com.demo30.case1.repository.UserRepo;
import com.demo30.case1.service.CheckUserService;
import com.demo30.case1.service.RealnameService;
import com.demo30.case1.service.UserService;
import com.demo30.case1.vo.Name;
import com.demo30.case1.vo.PhoneNumber;
import com.demo30.case1.vo.RealnameInfo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.xml.bind.ValidationException;
import java.util.ArrayList;
import java.util.List;

@Service
public class UserServiceImpl implements UserService {
    @Autowired
    private UserRepo userRepo;
    @Autowired
    private CheckUserService checkUserService;
    @Autowired
    private RealnameService realnameService;

    @Override
    public UserDTO register(Name name, PhoneNumber phone) throws ValidationException {
        // 查询实名信息(实名信息验证)
        RealnameInfo realnameInfo = realnameService.get(name, phone);
        // 构造对象
        User user = new User(realnameInfo, phone);
        // 检查User对象
        checkUserService.check(user);
        return new UserDTO(userRepo.save(user));
    }

    @Override
    public List<UserDTO> findList(UserParamDTO userParamDTO) {
        List<User> userList = userRepo.find(userParamDTO);

        List<UserDTO> userDTOList = new ArrayList<>();
        userList.forEach(user -> {
            userDTOList.add(new UserDTO(user));
        });

        return userDTOList;
    }

    @Override
    public UserDTO find(UserParamDTO userParamDTO) {
        if (null == userParamDTO.getUserId() || userParamDTO.getUserId().length() == 0) {
            return null;
        }
        User user = userRepo.findById(userParamDTO.getUserId());
        if (null != user) {
            return new UserDTO(user);
        }
        return null;
    }

    @Override
    public UserDTO setFresh(UserParamDTO userParamDTO) {
        if (null == userParamDTO.getUserId() || userParamDTO.getUserId().length() == 0) {
            return null;
        }
        User user = userRepo.findById(userParamDTO.getUserId());
        if (null != user) {
            // 设置用户为新客身份，以便发送新手礼包
            user.setFresh(true);
            // 检查User对象
            checkUserService.check(user);

            return new UserDTO(user);
        }
        return null;
    }

    @Override
    public Boolean deleteOne(UserParamDTO userParamDTO) {
        if (null == userParamDTO.getUserId() || userParamDTO.getUserId().length() == 0) {
            return false;
        }
        return userRepo.delete(userParamDTO.getUserId());
    }
}
