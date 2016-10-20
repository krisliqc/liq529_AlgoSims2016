//
//  Drop.cpp
//  w06_h04_ripple
//
//  Created by Kris Li on 10/13/16.
//
//

#include "Drop.hpp"

Drop::Drop(){
    radius = 7;
    theta = 0;
    init(ofPoint(0,0,-20), ofPoint(0,0,0), 0.15);
}

void Drop::init(ofPoint _pos, ofPoint _vel, float _damping){
    pos.set(_pos.x, _pos.y, _pos.z);
    vel.set(_vel.x, _vel.y, _pos.z);
    
    damping = _damping;
//    acc = ofPoint(0,0);
}

void Drop::update(){
    pos += vel;
    vel += acc;
    
    theta ++;
}

void Drop::vertical(ofPoint _pos){

}

void Drop::horizontal(ofPoint _pos, int _area){
    float distance = ofDist(_pos.x, _pos.y, pos.x, pos.y);
    float change;
    change = ofMap(distance, 0, 500, 10,0);
    
    if(distance > 500){
        change = 0;
    }
    vel.x = sin(theta)*change;
    vel.z = sin(theta+PI/2)*change;
}

void Drop::addDamping(){
    acc = acc - vel * damping;
}

void Drop::draw(){
    
    ofFill();
//    ofSetColor(22,149,163);
    ofSetColor(34,83,120);
//    ofSetColor(_color);
    ofDrawEllipse(pos,radius,radius);
}