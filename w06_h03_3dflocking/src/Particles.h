//
//  Particles.h
//  myFlocking
//
//  Created by Kris Li on 10/10/16.
//
//
#pragma once
#include "ofMain.h"


class Particle{
public:
    
    Particle();
    
    void init();
    void bounding();
    void draw();
    
    void update( vector<Particle> *particles );

    ofVec3f cohesion(vector<Particle> *particles);
    ofVec3f separation(vector<Particle> *particles);
    ofVec3f allignment(vector<Particle> *particles);
    
    ofVec3f seek();
    
    void avoid();
    
    ofVec3f pos;
    ofVec3f vel;
    int radius;
    

};