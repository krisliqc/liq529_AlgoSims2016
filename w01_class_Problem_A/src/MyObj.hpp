//
//  MyObj.hpp
//  w01_h01_Problem_A
//
//  Created by Kris Li on 9/1/16.
//
//

#pragma once //just do this for now

#include "ofMain.h"

class MyObj{

public:
    
    void draw();
    void setSrc(float _x, float _y);
    void setDst(float _x, float _y);
    
    void updatePct(float _pct);
    
    void powUpdatePct(float _pct, float _shaper);
    
//    void draw();
    
private:
    
    ofPoint src, dst;
    ofPoint pos;
    
};