//
//  Car.hpp
//  w06_h02_pathfollow2
//
//  Created by Kris Li on 10/14/16.
//
//

#pragma once
#include "ofMain.h"
#include "Path.hpp"

class Car{
    
public:
    Car();
    
    void init(ofPoint _start, ofPoint _end);
    void adjust();
    void seek(ofPoint _target);
    void update();
    void draw();
    
    
    ofPoint predictLoc;
    ofPoint start;
    ofPoint end;
    
private:
    
    ofPoint pos, vel, acc;
    float maxspeed;
    float maxforce;
    float r;
};