//
//  Car.cpp
//  w06_h02_pathfollow2
//
//  Created by Kris Li on 10/14/16.
//
//

#include "Car.hpp"

Car::Car(){
    pos.x = ofRandom(0,100);
    pos.y = ofRandom(ofGetHeight());
    
    maxspeed = 10;
    maxforce = 10;
    
    r = ofRandom(2,4);
}

void Car::init(ofPoint _start, ofPoint _end){
//    ofPoint start = _start;
//    ofPoint end = _end;
    vel = ofPoint(ofRandom(-3,3), ofRandom(-3,3));
}

void Car::adjust(){
    ofPoint a = ofPoint(predictLoc - start);
    ofPoint b = ofPoint(end - start);
    
    b.normalize();
    b*(a.dot(b));
    
    ofPoint normalPoint = start + b;
    
    float distance = ofDist(predictLoc.x, predictLoc.y, normalPoint.x, normalPoint.y);
    
    if(distance > 20){
        
        b.normalize();
        b*25;
        ofPoint target = normalPoint + b;
        seek(target);
    }
    
}

void Car::seek(ofPoint _target){
    ofPoint desired = _target - pos;
    desired.normalize();
    desired*maxspeed;
    
    ofPoint steer = desired - vel;
    acc += steer;
}

void Car::update(){
    pos += vel;
    vel += acc;
    vel.limit(maxspeed);
}


void Car::draw(){
//    float theta = vel.angleRad(vel) + PI/2;
    ofSetColor(50);
    ofSetLineWidth(2);
    ofPushMatrix();
    ofTranslate(pos.x,pos.y);
//    ofRotate(theta);
    ofBeginShape();
    ofVertex(0, -r*2);
    ofVertex(-r, r*2);
    ofVertex(r, r*2);
    ofEndShape();
    ofPopMatrix();
    
}

