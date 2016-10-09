//
//  Particle.cpp
//  2_Spring
//
//  Created by Regina Flores on 9/29/16.
//
//

#include "Particle.hpp"

Particle::Particle() {
    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;
    vel.set(0,0);
    acc.set(0,0);
    
    damp = 0.95; // de resistance!!!
    radius = 8;
    
    bFix = false;
}

void Particle::setInit(ofPoint _pos, ofPoint _vel){
    pos = _pos;
    vel = _vel;
    acc.set(0,0);
}
void Particle::update() {
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    
}

void Particle::bounding(){
    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
        pos.x -= vel.x; // Bounced back! think of this as an undo;
        vel.x *= -1.0;
    }
    
    if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
        pos.y -= vel.y; // Bounced back! think of this as an undo;
        vel.y *= -1.0;
    }
}

ofPoint Particle::getPosition(){
    return pos;
}

ofPoint Particle::getVelocity(){
    return vel;
}

float Particle::getRadius(){
    return radius;
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}

void Particle::addGravity(ofPoint _g){
    ofPoint g = _g;
    acc += g;
}

void Particle::reverse(ofPoint _f){
    vel -= _f;
}

void Particle::draw() {
    ofSetColor(0);
    ofDrawCircle(pos, radius);
    
}