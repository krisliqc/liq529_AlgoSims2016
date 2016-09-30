//
//  Particle.cpp
//  w04_h02_particle
//
//  Created by Kris Li on 9/28/16.
//
//

#include "Particle.hpp"

Particle::Particle(){
    setInitialCondition(ofPoint(0,0), ofPoint(0,0));
    
}

void Particle::setInitialCondition(ofPoint _pos, ofPoint _vel){
    
    pos.set(_pos.x, _pos.y);
    vel.set(_vel.x, _vel.y);
}

void Particle::update(){
    vel = vel + force;
    pos = pos + vel;
}

void Particle::resetForce(){
    force.set(0, 0);
}


void Particle::addRepulsionForce(ofPoint _pos, float _radius, float _strength){
    
    ofPoint posOfForce;
    posOfForce.set(_pos.x, _pos.y);
    
    ofPoint diff = pos - posOfForce;
    
    if(diff.length() < _radius){
        
        //smooth
        //        float pct = 1 - (diff.length() / _radius);
        //        diff.normalize();
        //        force += diff * pct * _strength;
        //wiggly
        diff *= ofMap(diff.length(), 0, _radius, 1.0, 0.0);
        force += diff * _strength;
        
    }
}

void Particle::addAttractionForce(ofPoint _pos, float _radius, float _strength){
    
    ofPoint posOfForce;
    posOfForce.set(_pos.x, _pos.y);
    
    ofPoint diff = pos - posOfForce;
    
    if(diff.length() < _radius){
        //smooth:
        //        float pct = 1 - (diff.length() / _radius);
        //        diff.normalize();
        //        force -= diff * pct * _strength;
        
        //wiggly:
        diff *= ofMap(diff.length(), 0, _radius, 1.0, 0.0);
        force -= diff * _strength;
    }
    
}

void Particle::bound(){
    if(pos.x <0 || pos.x > ofGetWidth()){
        vel.x = -0.05*vel.x;
    }
    if(pos.y <0 || pos.y > ofGetHeight()){
        vel.y = -0.05*vel.y;
    }
}

void Particle::draw(){
    ofCircle(pos, 5);
    
    
}

