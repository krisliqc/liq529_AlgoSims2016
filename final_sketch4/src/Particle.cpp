//
//  Particle.cpp
//  final_sketch4
//
//  Created by Kris Li on 12/9/16.
//
//

#include "Particle.hpp"

Particle::Particle(){
    attract = true;
}

void Particle::init(){
    pos = ofPoint(ofRandomHeight(), ofRandomWidth());
    vel = ofPoint(0,0,0);
    frc = ofPoint(0,0,0);
    rep = ofPoint(0,0,0);
    
    damp = 0.9;
}

void Particle::update(){
    
    ofPoint attractPt = ofPoint(ofGetMouseX(),ofGetMouseY());
    
    //attract and repulse
    if(attract == true){
        frc = attractPt - pos;
        frc.normalize();
        
    } else {
        // repulse
        frc = attractPt - pos;
        float dist = frc.length();
        frc.normalize();
        
        if(dist < 200){
            vel -= frc;
        }
    }
    
    vel += frc*0.25;
    vel *= damp;
    pos += vel;
    
}

void Particle::space(vector<Particle> *particles){
    for(int i = 0; i< particles->size(); i++){
        if (&(*particles)[i] == this) {
            continue;
        }
        float dist = ofDist((*particles)[i].pos.x,(*particles)[i].pos.y, pos.x, pos.y);
        if(dist < 30){
            rep = pos - (*particles)[i].pos;
            rep.normalize();
            vel += rep*0.25;
        }
    }
    
        float dist = ofDist(ofGetMouseX(),ofGetMouseY(), pos.x, pos.y);
        if(dist < 100){
            rep = pos - ofPoint(ofGetMouseX(),ofGetMouseY());
            rep.normalize();
            vel += rep;
        }
}

void Particle::bound(){
    if(pos.x < 0 || pos.x > ofGetWidth()){
        vel.x = -vel.x;
    }
    
    if(pos.y < 0 || pos.y > ofGetHeight()){
        vel.y = -vel.y;
    }
}

void Particle::draw(){
    
    for(int i=0; i < 10; i++){
        ofSetColor(0,88,169, 20-2*i);
        ofDrawCircle(pos, i*3);
        
    }
//    ofSetColor(255,80);
//    ofDrawCircle(pos, 3);
//    ofSetColor(255,50);
//    ofDrawCircle(pos, 15);
//    ofSetColor(255,10);
//    ofDrawCircle(pos, 35);
}






