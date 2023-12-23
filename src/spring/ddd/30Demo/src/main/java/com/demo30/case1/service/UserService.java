package com.demo30.case1.service;

import com.demo30.case1.dto.UserDTO;
import com.demo30.case1.dto.UserParamDTO;
import com.demo30.case1.vo.Name;
import com.demo30.case1.vo.PhoneNumber;
import org.springframework.web.bind.annotation.RequestBody;

import javax.xml.bind.ValidationException;
import java.util.List;

public interface UserService {
    UserDTO register(Name name, PhoneNumber phone) throws ValidationException;
    List<UserDTO> findList(UserParamDTO userParamDTO);
    UserDTO find(UserParamDTO userParamDTO);
    UserDTO setFresh(UserParamDTO userParamDTO);
    Boolean deleteOne(UserParamDTO userParamDTO);
}
