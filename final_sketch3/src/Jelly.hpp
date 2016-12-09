//
//  Jelly.hpp
//  final_sketch3
//
//  Created by Kris Li on 12/6/16.
//
//

#pragma once
#include "ofMain.h"
#include "Arm.hpp"
#include "Bell.hpp"
#include "Tenta.hpp"

class Jelly {
public:
    Jelly();
    void init(ofPoint _pos, ofPoint _vel);
    
    void addForce(ofPoint _force);
    void update(float rad1, float rad2);
    void bound();
    void draw();
    
    //bell
    Bell bell;
    Arm arm1;
    float rad1, rad2;
    
    //tenta
    vector<Tenta> tenticles;
    vector<ofPoint> links;
    int tentaSize;
    
private:
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    float damp;
    
};