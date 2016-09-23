//
//  particles.cpp
//  w03_h01
//
//  Created by Kris Li on 9/22/16, reference to Regina Flores
//
//

#include "particles.hpp"


void Particle::setup(){
    
    pos.x = ofGetWidth()/2+ofRandom(-10,10);
    pos.y = 200+ofRandom(-5,5);
    radius = ofRandom(2,5);
    
    vel.x = ofRandom(-5,5);
    vel.y = ofRandom(-10,-5);
    
    color = ofColor(ofRandom(200,255), ofRandom(200,255), 200);
    
    someNumber = ofRandom(1,400);
}

void Particle::explosion(){
    
    pos = pos + vel;
    
}

void Particle::update(){
    vel.y += 0.5;
}

void Particle::draw(){
    
    ofSetColor(color);
    ofEllipse(pos.x, pos.y, radius, radius);
    
}

void Particle::restart(){
    
//    pos.x = ofGetWidth()/2+ofRandom(-10,10);
//    pos.y = 200+ofRandom(-5,5);
    
    pos.x = ofGetMouseX()+ofRandom(-10,10);
    pos.y = ofGetMouseY()+ofRandom(-5,5);
    
    vel.x = ofRandom(-5,5);
    vel.y = ofRandom(-10,-5);
    
}



