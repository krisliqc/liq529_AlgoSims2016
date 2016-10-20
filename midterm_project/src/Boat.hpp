//
//  Boat.hpp
//  w07_h01_ripple
//
//  Created by Kris Li on 10/18/16.
//
//

#pragma once
#include "ofMain.h"

class Boat{
public:
    Boat();
    
    void init(ofPoint _pos, ofPoint _vel = ofPoint(0,0));

    ofPoint getPosition();
    float   getRadius();
    
    void addForce(ofPoint _force);
    
    void addRepulsionForce(ofPoint _pos, float _rad, float _scale);
    void addAttractionForce(ofPoint _pos, float _rad, float _scale);
    
    void seek( ofPoint dest );
    
    void update();
    void draw();
    
    ofColor color;
    
private:
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    float radius;
    float damp;
    
    ofImage boat1;
    ofImage boat2;
};
