//
//  Boat.cpp
//  w07_h01_ripple
//
//  Created by Kris Li on 10/18/16.
//
//

#include "Boat.hpp"

Boat::Boat(){
    
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    pos.z = 50;
    
    vel.set(0,0);
    
    damp = 0.95;
    radius = 5;
    
    boat1.load("boat1.png");
    boat2.load("boat2.png");
}

void Boat::init(ofPoint _pos, ofPoint _vel){
    pos = _pos;
    vel = _vel;
}

ofPoint Boat::getPosition(){
    return pos;
}

float Boat::getRadius(){
    return radius;
}

void Boat::addForce(ofPoint _force){
    acc += _force;
}

void Boat::addRepulsionForce(ofPoint _pos, float _rad, float _scale){
    ofPoint diff = _pos - pos;
    if(diff.length() < _rad) {
        diff *= 1.0 -diff.length()/_rad;
        addForce(-diff*_scale);
    }
}

void Boat::addAttractionForce(ofPoint _pos, float _rad, float _scale){
    ofPoint diff = _pos - pos;
    if(diff.length() < _rad) {
        diff *= 1.0 -diff.length()/_rad;
        addForce(diff*_scale);
    }
}

void Boat::seek( ofPoint _dest){
    float maxSpeed = 10.0;
    float maxForce = 0.4;
    
    float slowDownRadius = 200.0;
    
    ofPoint desired = _dest - pos;
    
    if( desired.length() < slowDownRadius ){
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        
        desired.normalize();
        desired *= newMag;
    }else{
        desired.normalize();
        desired *= maxSpeed;
    }
    
    ofPoint steer = desired - vel;
    steer.limit( maxForce );
    
    addForce( steer );
}


void Boat::update(){
    pos += vel;
    vel += acc;
    vel *= damp;
    acc *= 0.0;
    
    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
        pos.x -= vel.x;
        vel.x *= -1.0;
    }
    
    if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
        pos.y -= vel.y;
        vel.y *= -1.0;
    }
}

void Boat::draw(){
    ofPushMatrix();
    ofTranslate(pos);
    ofSetColor(255);
    float rotAmt = atan2( vel.y,vel.x);
    ofRotate( ofRadToDeg(rotAmt) -90);
    boat1.draw(-30, 0,60,50);
    ofPopMatrix();
}




