//
//  Moon.hpp
//  w04_h01_moons
//
//  Created by Kris Li on 9/29/16.
//
//

#pragma once
#include "ofMain.h"

class Moon : public ofPoint {
public:
    
    void set(float _dist, float _intAngle);
    void update(float _step, ofPoint _center);
    
    void draw();
    
    float radius;
    float angle;
};