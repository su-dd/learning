package com.demo30.case2.domain.ability;


import com.demo30.case2.domain.model.valueobjects.Name;
import com.demo30.case2.domain.model.valueobjects.PhoneNumber;
import com.demo30.case2.domain.model.valueobjects.RealnameInfo;

import javax.xml.bind.ValidationException;

public interface RealnameService {
    RealnameInfo get(Name name, PhoneNumber phoneNumber) throws ValidationException;
}
