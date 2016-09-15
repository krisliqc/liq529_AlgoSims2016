//
//  mover.hpp
//  w02_h03_atan2
//
//  Created by Kris Li, reference to Regina Flores on 9/14/16.
//
//

#pragma once

#include "ofMain.h"

class mover {
    
public:
    mover();
    void draw();
    
    void xenoToPoint(float catchX, float catchY);
    
    ofPoint pos;
    float catchUpSpeed;
    
    
private:
    
    
};