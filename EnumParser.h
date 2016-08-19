//
//  EnumParser.h
//  EaseTool
//
//  Created by Paulo Fernandes on 19/08/16.
//  Copyright © 2016 Paulo Fernandes. All rights reserved.
//

#ifndef EnumParser_h
#define EnumParser_h

#pragma once
#include <map>
#include <exception>

/*
 *  Template to handle string input and return EaseType using a map
 */
template <typename K, typename T>
class EnumParser
{
    std::map <K, T> enumMap;
public:
    EnumParser(){};
    
    T ParseEnum(const K &value)
    {
        typename std::map <K, T>::const_iterator iValue = enumMap.find(value);
        if (iValue  == enumMap.end())
            throw std::invalid_argument("Invalid Argument to Parse!"); // string don't exists in enumMap
        return iValue->second;
    }
};

#endif /* EnumParser_h */
