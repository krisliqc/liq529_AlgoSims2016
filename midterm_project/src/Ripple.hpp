//
//  Ripple.hpp
//  w07_h01_ripple
//
//  Created by Kris Li on 10/17/16.
//
//

#pragma once
#include "ofMain.h"

class Ripple {
public:
    
    Ripple();
    void init(ofPoint _pos);
    void update(vector<Ripple> *ripples, float _wave);
//    void collide();
    
    float collide(vector<Ripple> *ripples);
    
    void addForce(ofPoint _acc);
    void draw(int _rippleM);
    
    
private:
    
    ofPoint pos, vel, acc;
    
    int radius, size;
    int num;
    float opacity;
    float theta;
};