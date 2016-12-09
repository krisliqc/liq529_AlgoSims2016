//
//  Bell.hpp
//  final_sketch2
//
//  Created by Kris Li on 12/1/16.
//
//

#pragma once
#include "ofMain.h"

class Bell {
public:
    
    Bell();
    void init(ofPoint pos);
    void update(float rad1, float rad2);
    void draw();
    
    ofMesh bell;
    
    int gridScale;
    int size;
    
    float theta;
    float phi;
    
    int radius;
    int i1,i2,i3,i4;

};