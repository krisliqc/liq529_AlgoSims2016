//
//  Drop.cpp
//  w06_h04_ripple
//
//  Created by Kris Li on 10/13/16.
//
//

#include "Drop.hpp"

Drop::Drop(){
    radius = 5;
    theta = 0;
    init(ofPoint(0,0), ofPoint(0,0));
    damping = 0.15;
}

void Drop::init(ofPoint _pos, ofPoint _vel){
    pos.set(_pos.x, _pos.y);
    vel.set(_vel.x, _vel.y);
//    acc = ofPoint(0,0);
}

void Drop::update(){
    pos += vel;
    vel += acc;
    
    theta ++;
}

void Drop::vertical(ofPoint _pos){

}

void Drop::horizontal(ofPoint _pos){
    float dist = ofDist(_pos.x, _pos.y, pos.x, pos.y);
    float change;
    change = ofMap(dist, 0, 500, 10,0);
    
    if(dist > 500){
        change = 0;
    }
    vel.x = sin(theta)*change;
}

void Drop::addDamping(){
    acc = acc - vel * damping;
}

void Drop::draw(){
    
//    ofSetColor(_color);
    ofDrawEllipse(pos,radius,radius);
}