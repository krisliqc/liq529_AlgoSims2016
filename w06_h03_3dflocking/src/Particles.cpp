//
//  Particles.cpp
//  myFlocking
//
//  Created by Kris Li on 10/10/16.
//
//

#include "Particles.h"


Particle::Particle(){
    
    radius = 2;

}

void Particle::init(){
    
    //defining the position and velocity of the particles
    //Note: we translate origin (0,0) to middle of screen
    pos = ofVec3f(ofRandom(-ofGetWidth()/2, ofGetWidth()/2),ofRandom(-ofGetHeight()/2, ofGetHeight()/2),ofRandom(-ofGetHeight()/2, ofGetHeight()/2));

    vel = ofVec3f(ofRandom(-3, 3), ofRandom(-3, 3),ofRandom(-3, 3));
    
}

void Particle::bounding(){
    
    //keeping the particles inside the screen
    //note: the new screen width is (-w/2,w/2), same for height
//    if(pos.y > ofGetHeight()/2 || pos.y < -ofGetHeight()/2){
//        vel = -vel;
//    }
//    if(pos.x > ofGetWidth()/2 || pos.x < -ofGetWidth()/2){
//        vel = -vel;
//    }
    if(pos.y > ofGetHeight() || pos.y < 0){
        vel.y = -vel.y;
    }
    if(pos.x > ofGetWidth() || pos.x < 0){
        vel.x = -vel.x;
    }

}


void Particle::draw(){
    
        ofDrawCircle(pos.x, pos.y, pos.z, radius);
}

ofVec3f Particle::cohesion(vector<Particle> *particles){
    ofVec3f centerMass;
    for(int i = 0; i < particles->size(); i++){
        if (&(*particles)[i] == this) {
            continue;
        }
        
        
        //2 vectors: the velocity vector and the distance between self and target
        //check to see if the two vectors are in different directions
        //
        
        ofVec3f vec1 = vel.normalize();
        ofVec3f vec2 = (*particles)[i].pos - pos;
        float dirCos = vec1.dot(vec2);
        
        if(dirCos < 0){
            continue;
        }
        
        centerMass += (*particles)[i].pos;
    
    }
    centerMass = centerMass/(particles->size()-1);
    
    ofVec3f cohesion_velocity;
    cohesion_velocity = (centerMass-pos)/100.0f;
    return cohesion_velocity;
    
    
    
}

ofVec3f Particle::separation(vector<Particle> *particles){
    
    ofVec3f displace;
    for(int i = 0; i < particles->size(); i++){
        if (&(*particles)[i] == this) {
            continue;
        }

//        float dist = pow((*particles)[i].pos.x - pos.x, 2) + pow((*particles)[i].pos.y - pos.y, 2);
//        dist = sqrt(dist);
        
        float dist = ofDist((*particles)[i].pos.x, (*particles)[i].pos.y, (*particles)[i].pos.z, pos.x, pos.y, pos.z);

        if (dist < 50.0) {
            displace  = displace - ((*particles)[i].pos - pos);
        }
        
    }
    
    ofVec3f separation_velocity;
    separation_velocity = displace;
    return separation_velocity;
}

ofVec3f Particle::allignment(vector<Particle> *particles){

    
    ofVec3f aveVel;
    for(int i = 0; i < particles->size(); i++){
        if (&(*particles)[i] == this) {
            continue;
        }
        
        aveVel += (*particles)[i].vel;
        
    }
    
    aveVel = aveVel/(particles->size()-1);
    
    ofVec3f allignment_velocity;
    allignment_velocity = (aveVel - vel)/8.0f;
    return allignment_velocity;
    
}

ofVec3f Particle::seek(){
    ofVec3f mouseDist = (ofGetMouseX(),ofGetMouseY(),ofRandom(100))-pos;
    ofVec3f seek = mouseDist/500;
    return seek;
}

//avoid the center of the screen
void Particle::avoid(){
 
    float centerDist;
    centerDist = ofDist(pos.x, pos.y, pos.z, ofGetWidth()/2, ofGetHeight()/2, 0);
    if(centerDist < 200) {
        vel = -vel;
    }
}


void Particle:: update( vector<Particle> *particles ){
    
    ofVec3f v1 = cohesion(particles);
    ofVec3f v2 = separation(particles);
    ofVec3f v3 = allignment(particles);
    ofVec3f v4 = seek();
    
    vel += v1 + v2 + v3 + v4;
    pos = pos + vel/2;
    
}


