//
//  Xtring.cpp
//  w05_h01_strings
//
//  Created by Kris Li on 10/5/16.
//
//

#include "Xtring.hpp"

Xtring::Xtring() {
//    pos.x = ofRandom(ofGetWidth());
//    pos.y = ofRandom(ofGetHeight());
    
    vel.set(0,0);

}

void Xtring::setInit(){
    
    ofPoint ran;
    ran = ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    
    for(int i =0; i < 3; i++){
        particles[i].setInit(ran, ofPoint(ofRandom(-2,2),ofRandom(-2,2)));
    }
    
    particles[0].bFix = true;
    
    //spring array
    springs[0].set(&particles[0], &particles[1]);
    springs[0].restDist = 250;
    springs[1].set(&particles[1], &particles[2]);
    springs[1].restDist = 150;
}


void Xtring::update() {
    
    for(int i =0; i< 2; i++){
        springs[i].update();
    }
    
    for(int i = 0; i < 3; i++){
        particles[i].addForce(ofPoint(0,0.1));
        particles[i].update();
        particles[i].bounding();
        particles[i].avoid(ofPoint(100,400));
        particles[i].avoid(ofPoint(700,200));
    }
    
}

//void Xtring::bound() {
//    if( pos.x < 0.0 || pos.x > ofGetWidth()){
////        pos.x -= vel.x;
//        vel.x = -vel.x; // come back at a slower speed
//    }
//    
//    if( pos.y < 0.0 || pos.y > ofGetHeight()){
////        pos.y -= vel.y;
//        vel.y = -vel.y;
//    }
//}


void Xtring::draw() {
    
    for(int i =0; i< 2; i ++){
        springs[i].draw();
    }
    
    for(int i = 0; i < 3; i ++){
        particles[i].draw();
    }
}

