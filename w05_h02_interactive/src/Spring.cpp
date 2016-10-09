//
//  Spring.cpp
//  springsPointers
//
//  Created by Regina Flores on 9/29/16.
//
//

#include "Spring.hpp"

Spring::Spring(){

    
    A = NULL;
    B = NULL;

}

void Spring::set(Particle *_A, Particle *_B, float _k){
    
    
    k = _k;
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
    ofSetColor(0);
    ofSetLineWidth(3);
    ofDrawLine(A->getPosition(), B->getPosition());
}










