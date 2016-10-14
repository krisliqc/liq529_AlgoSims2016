//
//  Car.cpp
//  w06_h02_pathfollow
//
//  Created by Kris Li on 10/13/16.
//
//

#include "Car.hpp"

Car::Car(){
    size = 5;
}

void Car::init(){
    
    pos.x = ofRandom(50,150);
    pos.y = ofRandom(250,350);
    vel = ofPoint(ofRandom(-3,3),ofRandom(-3,3));
}


ofPoint Car::seek(ofPoint _end){
    ofPoint desired = _end - pos;
    desired.normalize();
    
    v1 = desired * 3;
    return v1;
    
}

ofPoint Car::follow(ofPoint _begin, ofPoint _end){
 
    ofPoint predict;
    predict = pos + vel.normalize()*25;
    
    ofPoint a,b;
    a = predict - _begin;
    b = _end - _begin;
    
//    float theta =a.angle(b);
//    b.normalize();
//    b*(a.length()*cos(theta));
//    ofPoint normalPoint = _begin + b;
    
    b.normalize();
    b*(a.dot(b));
    ofPoint normalPoint = _begin + b;
    
    float distance = ofDist(predict.x,predict.y, normalPoint.x, normalPoint.y);
    
    if(distance > 50){
        v1 = this->seek(_end);
    } else {
        v1 = ofPoint(0,0);
    }
    
    return v1;
}


void Car::update(ofPoint _begin, ofPoint _end){
    pos += vel;
    vel += v1;
    
    //set a maximum velocity
    if(vel.length() > 20){
        vel.normalize();
        vel*20;
    }
}

void Car::draw(){
    ofDrawRectangle(pos, size, size);
}