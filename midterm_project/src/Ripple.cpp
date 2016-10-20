//
//  Ripple.cpp
//  w07_h01_ripple
//
//  Created by Kris Li on 10/17/16.
//
//

#include "Ripple.hpp"

Ripple::Ripple(){
    init(ofPoint(100,100));
    num = 20;
    radius = 0;
    opacity = 100;
    theta = 0;
}

void Ripple::init(ofPoint _pos){
    pos.set(_pos.x, _pos.y);
    
}

void Ripple::update(vector<Ripple> *ripples, float _wave){
    pos += vel;
    vel += acc;
    
    radius++;
    if(radius > 400){
        opacity --;
    }
    
    theta += PI/_wave;
    
//    if(pos.x + radius > )
    
//    opacity = collide(ripples);
}

void Ripple::addForce(ofPoint _acc){
    vel += _acc;
}

float Ripple::collide(vector<Ripple> *ripples){
    
    for(int i =0; i<ripples->size(); i++){
        if(&(*ripples)[i] ==this){
            continue;
        }
        
        float dist = ofDist(pos.x, pos.y, (*ripples)[i].pos.x,(*ripples)[i].pos.y);
        
        float waveRadius = radius + (*ripples)[i].radius;
        float overlap = waveRadius - dist;
        
        if(overlap>0 && overlap<200){
            float opacity_collide = ofMap(overlap, 0, 200, 100, 0);
            return opacity_collide;
            
            
        } else {
            continue;
        }
    }
    
}


void Ripple::draw(int _rippleM){
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(172, 240, 242,opacity);
    
    for(int i =0; i<num; i++){
        
        pos.z = sin(theta*i)*5;
        size =i*i*i/_rippleM+radius;
        ofDrawEllipse(pos.x, pos.y,pos.z,size,size);
    }
}



