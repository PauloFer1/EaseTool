//
//  Tween.h
//  EaseTool
//
//  Created by Paulo Fernandes on 18/08/16.
//  Copyright © 2016 Paulo Fernandes. All rights reserved.
//

#ifndef Tween_h
#define Tween_h

#pragma once
#include <memory>
#include <vector>
#include <iostream>
#include <functional>
#include "EnumParser.h"

struct EaseLinear{int operator()(float t, int initialX, float durationSecs) const {return static_cast<int>(initialX * (t + durationSecs));}};

struct Print{void operator()(int value) {std::cout << value << std::endl;}};


typedef std::shared_ptr<class Tween> TweenRef;

/*
 * Template for Functions
 */
template<typename T>
class TweenEase;
typedef std::function<int (float, int, int, float)> EaseFunction;
typedef std::function<int (float, int, int, float)> ArcFunction;

/*
 * Easing functions definition
 */
inline int easeLinear(float t, int initialX, int finalX, float durationSecs){return static_cast<int>((finalX-initialX) * (t + durationSecs)); };
inline int easeInQuad(float t, int initialX, int finalX, float durationSecs){return static_cast<int>((finalX-initialX) * (t*t + durationSecs)); };
inline int easeOutQuad(float t, int initialX, int finalX, float durationSecs){return static_cast<int>((finalX-initialX) * (t*t + durationSecs)); };
inline int easeInOutQuad(float t, int initialX, int finalX, float durationSecs){ t*=2; float temp = t-1; float lastVal = t<1?(0.5f*t*t):(-0.5f*(temp*(temp-2)-1));    return static_cast<int>((finalX-initialX) * (lastVal + durationSecs)); };




class Tween : public std::enable_shared_from_this<Tween>
{
public:
    enum EaseType{Linear, InQuad, OutQuad, InOutQuad, ArcX, ArcY}; // Type of easing functions
    //Constructors
    Tween(int initialX, int finalX, float durationSecs, EaseFunction easeFunction, std::vector<float> inputTimeSecs):
    mInitialX(initialX),
    mFinalX(finalX),
    mDurationSecs(durationSecs),
    mEaseFunction(easeFunction),
    mInputTimeSecs(inputTimeSecs){};
    
    // GETTERS
    int                 getInitialX(){return mInitialX;};
    int                 getFinalX(){return mFinalX;};
    float               getDurationSecs(){return mDurationSecs;};
    std::vector<int>    getOutputValues(){return mOutputValues;};
    
    // SETTERS
    void                setNewTween(int initialX, int finalX, float durationSecs, EaseFunction easeFunction, std::vector<float> inputTimeSecs){
                            mInputTimeSecs.erase(mInputTimeSecs.begin(), mInputTimeSecs.end());
                            mOutputValues.erase(mOutputValues.begin(), mOutputValues.end());
                            mInitialX = initialX;
                            mFinalX = finalX;
                            mDurationSecs = durationSecs;
                            mInputTimeSecs = inputTimeSecs;
                            mEaseFunction = easeFunction;
        
                        }
    
    // METHODS
    void                apply(){for_each(mInputTimeSecs.begin(), mInputTimeSecs.end(), [&](float t)
                                         {
                                             mOutputValues.push_back(mEaseFunction(t, mInitialX, mFinalX, mDurationSecs));
                                         });
                        };
    
    void printValues(){
        for_each(mOutputValues.begin(), mOutputValues.end(), [](int val){ std::cout << val << std::endl;});
    };
    
    
private:
    int                     mInitialX;
    int                     mFinalX;
    float                   mDurationSecs;
    EaseType                mEaseType;
    std::vector<float>      mInputTimeSecs;
    std::vector<int>        mOutputValues;
    EaseFunction            mEaseFunction;
};

#endif /* Tween_h */
