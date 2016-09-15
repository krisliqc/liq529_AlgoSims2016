//
//  MyBall.hpp
//  BouncingBall
//
//  Created by Kris Li, reference to Regina Flores on 9/14/16.
//
//

#pragma once

#include "ofMain.h"

class MyBall {
    
    
public:
    
    MyBall();
    
    void update();
    void draw();
    
    ofPoint position;
    
    ofVec2f velocity;
    
    float dist;
    
};
