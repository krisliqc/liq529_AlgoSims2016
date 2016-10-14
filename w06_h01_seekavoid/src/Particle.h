#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    
    void setInit(ofPoint _pos, ofPoint _vel = ofPoint(0,0));
    
    ofPoint getPosition();
    float   getRadius();
    
    void addForce(ofPoint _force);
    
//    void addRepulsionForce(ofPoint _pos, float _rad, float _scale);
//    void addAttractionForce(ofPoint _pos, float _rad, float _scale);
    
    ofPoint separation(vector<Particle> &particles);
    
    void seek( ofPoint dest );
    
    void update(vector<Particle> &particles);
    void draw();
    
    ofColor color;
    
private:
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    float radius;
    float damp;
    
    ofImage fish;
};