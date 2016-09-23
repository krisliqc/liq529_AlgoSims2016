//
//  Wave.hpp
//  w03_h02_sincos
//
//  Created by Kris Li on 9/22/16.
//
//

#pragma once
#include "ofMain.h"

class Wave {
    
public:
    
    Wave();
    
    void setup();
    
    void update();
    
    void draw();
    
    void avoid();
    
    ofPoint pos1, pos2;
    
    ofPoint vel;
    
    float h;
    
//    ofPath path;
};