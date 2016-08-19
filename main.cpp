//
//  main.cpp
//  EaseTool
//
//  Created by Paulo Fernandes on 18/08/16.
//  Copyright © 2016 Paulo Fernandes. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Tween.h"
#include "Parser.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    vector<float> values;
    values.push_back(0.2);
    values.push_back(0.5);
    values.push_back(1.0);
    
  // string lineBuf;
   // getline(cin, lineBuf);
    
    Parser mParser("OutQuad,x_t0=100, x_tmax=200,duration=1");
    mParser.parseString();
    //cout << "Parser: " << mParser.getEaseType() << endl;
    
    cout << "Linear:" << endl;
    Tween tween(100, 200, 1, easeLinear, values);
    tween.apply();
    tween.printValues();
    
    cout << "InQuad:" << endl;
    tween.setNewTween(0, 100, 1, easeInQuad, values);
    tween.apply();
    tween.printValues();
    
    cout << "OutQuad:" << endl;
    tween.setNewTween(0, 100, 1, easeInOutQuad, values);
    tween.apply();
    tween.printValues();
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
