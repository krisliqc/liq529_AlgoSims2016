//
//  particles.hpp
//  w03_h01
//
//  Created by Kris Li on 9/22/16.
//
//

#pragma once

#include "ofMain.h"

class Particle{
    
public:
    
    void draw();
    void setup();
    void explosion();
    void update();
    
    void restart();
    
    ofPoint pos;
    ofPoint vel;
    ofColor color;
    
    float radius;
    int someNumber;
    
};


