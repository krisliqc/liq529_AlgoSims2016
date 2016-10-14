//
//  Car.hpp
//  w06_h02_pathfollow
//
//  Created by Kris Li on 10/13/16.
//
//

#pragma once
#include "ofMain.h"

class Car {
public:
    Car();
    
    void init();
    
//    void follow();
    ofPoint seek(ofPoint _end);
    ofPoint follow(ofPoint _begin, ofPoint _end);
    
    void update(ofPoint _begin, ofPoint _end);
    void draw();
    
    ofColor on, off;
    
private:
    
    ofPoint pos;
    ofPoint vel;
    ofPoint v1;
    
    float size;
};
