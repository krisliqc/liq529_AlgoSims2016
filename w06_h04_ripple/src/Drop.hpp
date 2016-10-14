//
//  Drop.hpp
//  w06_h04_ripple
//
//  Created by Kris Li on 10/13/16.
//
//

#pragma once
#include "ofMain.h"

class Drop {
public:
    Drop();
    void init(ofPoint _pos, ofPoint _vel);
    void update();
    void addDamping();
    void draw();
    void vertical(ofPoint _pos);
    void horizontal(ofPoint _pos);
    
private:
    
    ofPoint pos, vel, acc;
    float damping;
    int radius;
    
    float theta;
    
};
