//
//  MyObj.cpp
//  w01_h01_Problem_A
//
//  Created by Kris Li on 9/1/16.
//
//

#include "MyObj.hpp"

void MyObj::setSrc(float _x, float _y){
    src.set(_x, _y);
    
}

void MyObj::setDst(float _x, float _y){
    dst.set(_x, _y);
}

//fomulas for using power function
//pct = powf(num,exp); myPoss = (1-pct) * a + pct * b;

void MyObj::powUpdatePct(float _pct, float _shaper){
    
    float Powpct = powf(_pct, _shaper);
    pos = dst * Powpct + src*(1.0 - Powpct);
}

// _is for something you're passing that will be needed for the function

void MyObj::draw(){
    
    ofSetColor(255,255,255,200);
    ofLine(src, dst);
    
    ofSetColor(255,0,0);
    ofCircle(pos,10);
}