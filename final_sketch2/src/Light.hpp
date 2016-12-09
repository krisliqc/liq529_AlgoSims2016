//
//  Light.hpp
//  final_sketch2
//
//  Created by Kris Li on 12/1/16.
//
//

#pragma once
#include "ofMain.h"

class Light {
public:
    
    Light();
    void init(ofPoint _pos);
    void update();
    void draw();
    
    ofPoint pos;
    
private:
    
};