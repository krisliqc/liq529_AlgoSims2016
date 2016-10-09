//
//  Particle.cpp
//  w05_h01_strings
//
//  Created by Kris Li on 10/5/16.
//
//

#include "Particle.hpp"

Particle::Particle() {
    pos.x = ofRandom(ofGetWindowWidth());
    pos.y = ofRandom(ofGetHeight());
    
    vel.set(0,0);
    acc.set(0,0);
    
    damp = 0.90; // damping force--resistance
    radius = 5;
    
    bFix = false;
    
    color = ofColor(ofRandom(100, 250),ofRandom(100, 250),ofRandom(0, 120));
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
    
//    vel = ofPoint(ofRandom(-5,5),ofRandom(-5,5));
//    ofPoint dir = 0.005*ofPoint(ofGetWidth()/2, ofGetHeight()/2)-ofPoint(ofGetMouseX(),ofGetMouseY());
     ofPoint dir = ofPoint(ofGetMouseX(),ofGetMouseY())-ofPoint(pos.x, pos.y);
    
    
    dir = dir/(ofRandom(1,20));
    dir.normalize();
    
    acc= dir;
}

void Particle::bounding(){
//    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
//        pos.x -= vel.x;
//        vel.x *= -0.5; // come back at a slower speed
//    }
//    
//    if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
//        pos.y -= vel.y;
//        vel.y *= -0.5;
//    }
    if( pos.x < 0.0 || pos.x > ofGetWidth()){
        pos.x -= vel.x;
        vel.x *= -0.5; // come back at a slower speed
    }
    
    if( pos.y < 0.0 || pos.y > ofGetHeight()){
        pos.y -= vel.y;
        vel.y *= -0.5;
    }
}

void Particle::avoid(ofPoint ball){
    if(ofDist(ball.x, ball.y,pos.x, pos.y)< 50){
        ofPoint f = ofPoint(ball.x - pos.x, ball.y - pos.y);
        vel -= f;
    }
}

ofPoint Particle::getPosition(){
    return pos;
}

ofPoint Particle::getVelocity(){
    return vel;
}

ofColor Particle::getColor(){
    return color;
}

float Particle::getRadius(){
    return radius;
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}

void Particle::draw() {
    ofSetColor(color);
    ofDrawCircle(pos, radius);
}