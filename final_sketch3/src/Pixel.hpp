//
//  Pixel.hpp
//  w08_h01_noise
//
//  Created by Kris Li on 11/2/16.
//
//

#pragma once
#include "ofMain.h"

class Pixel {
public:
    
    Pixel();
    void init(ofPoint _pos);
    void update(vector<ofPoint> *lights);
    void draw(int _size);
    
    ofPoint pos;
    int size;
    int r, g, b;
    
    float dist;
    int range;
    
private:
    
};