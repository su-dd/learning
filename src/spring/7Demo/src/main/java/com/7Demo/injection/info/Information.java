package com.7Demo.injection.info;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

public interface Information {
    public default String info() {
        return toString();
    }
}
