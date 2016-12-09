//
//  Particle.hpp
//  final_sketch4
//
//  Created by Kris Li on 12/9/16.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    Particle();
    
    void init();
    void update();
    void space(vector<Particle> *particles);
    void bound();
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;
    ofPoint rep;
    float damp;
    
    Boolean attract;
    
    vector <ofPoint> *attractPoints;
    
};