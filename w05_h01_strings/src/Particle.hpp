//
//  Particle.hpp
//  w05_h01_strings
//
//  Created by Kris Li on 10/5/16.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    
    void setInit(ofPoint _pos, ofPoint _vel = ofPoint(0,0));
    
    float   getRadius();
    ofPoint getPosition();
    ofPoint getVelocity();
    ofColor getColor();
    
    void addForce(ofPoint _force);
    void bounding();
    void avoid(ofPoint _ball);
    
    void update();
    void draw();
    
    bool bFix;
    
    //private:
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    float radius;
    float damp;
    
    ofColor color;
    
};