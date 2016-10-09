//
//  Spring.cpp
//  w05_h01_strings
//
//  Created by Kris Li on 10/5/16.
//
//

#include "Spring.hpp"

Spring::Spring(){
    
    
    A = NULL;
    B = NULL;
    
    k = 0.6;
    
}

void Spring::set(Particle *_A, Particle *_B){
    
    A = _A;
    B = _B;
    
    //New notation:
    //"->" if you have a pointer to an object and you want to call that object's funtion
    
    restDist = A->getPosition().distance(B->getPosition());
}

void Spring::update(){
    
    if(A == NULL || B == NULL){
        return;
    }
    
    //pointer notation to implement Hooke's Law
    //steps of making the spring "springy"
    ofVec2f force = A->pos - B->pos;
    float currentLength = force.length();
    float x = currentLength - restDist;
    
    //Tao and Nick vector math working group
    force.normalize();
    
    force *= k *x; //hookes law
    
    if(A->bFix){
        A->addForce(-force*0.5);
    }
    B->addForce(force*0.5);
    
}

void Spring::draw(){
    
    if(A == NULL || B == NULL){
        return;
    }
    
    ofSetColor(A->getColor());
    
    ofSetLineWidth(2);
    ofDrawLine(A->getPosition(), B->getPosition());
}

