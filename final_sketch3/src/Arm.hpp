//
//  Arm.hpp
//  final_sketch3
//
//  Created by Kris Li on 12/6/16.
//
//

#pragma once
#include "ofMain.h"

class Arm {
public:
    Arm();
    
    void init();
    void update(ofPoint _pos);
    void draw();
    
    int width;
    
    vector<ofPoint> anchors;
    int anchorSize;
    vector<ofPoint> hairs;
    
    ofMesh ruffle;
    
    float noise;
    
private:
    ofPoint pos;
};