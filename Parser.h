//
//  Parser.h
//  EaseTool
//
//  Created by Paulo Fernandes on 19/08/16.
//  Copyright © 2016 Paulo Fernandes. All rights reserved.
//
#pragma once
#include <string>
#include <map>
#include "Tween.h"
#include <sstream>

#ifndef Parser_h
#define Parser_h



/*
 * Initialize Map with ease type values, has the possibility to add more
 */
template<> EnumParser<std::string, Tween::EaseType>::EnumParser(){
    enumMap["Linear"] = Tween::EaseType::Linear;
    enumMap["InQuad"] = Tween::EaseType::InQuad;
    enumMap["OutQuad"] = Tween::EaseType::OutQuad;
    enumMap["InOutQuad"] =Tween::EaseType::InOutQuad;
    enumMap["ArcX"] = Tween::EaseType::ArcX;
    enumMap["ArcY"] = Tween::EaseType::ArcY;
}
/*
 * Initialize Map with functions
 */
template<> EnumParser<std::string, EaseFunction>::EnumParser(){
    enumMap["Linear"] = easeLinear;
    enumMap["InQuad"] = easeInQuad;
    enumMap["OutQuad"] = easeOutQuad;
    enumMap["InOutQuad"] = easeInQuad;
}

class Parser
{
    enum InputType{};
public:
    Parser(std::string inputStr){mInputStr = inputStr;};
    
    // GETTERS
    Tween::EaseType     getEaseType(){ EnumParser<std::string, Tween::EaseType> parser; return parser.ParseEnum(mInputStr); };
    
    // METHODS
    
    /*
     * parse input string to commands and vars
     */
    void parseString()
    {
        std::vector<std::string> inputs;
        std::string tmpStr;
        
        std::stringstream input(mInputStr); // put string into a stringstream to use getline
        
        int counter =0; // to count number of params
        
        while(std::getline(input, tmpStr, ','))
        {
            inputs.push_back(tmpStr);
            std::cout << "input: " << tmpStr << std::endl;
            if(counter == 0)
            {
                EnumParser<std::string, Tween::EaseType> parser;
                try{
                    parser.ParseEnum(tmpStr);
                }
                catch(std::exception &e){
                    std::cout << "Command Invalid!" << std::endl;
                    return;
                }
            }
            else
            {
                std::stringstream param(tmpStr);
                std::string value;
                while(std::getline(param, value, '='))
                {
                    if(value.compare("x_t0")==0)
                }
                
            }
            counter++;
        }
        
    }
    
private:
    std::string         mInputStr; // input string to parse
    int                 mXT0; // starting position at time 0
    int                 mXTmax; // ending position at time duration
    float               mDuration; // duration of the movement denoted by input parameter
};


#endif /* Parser_h */
