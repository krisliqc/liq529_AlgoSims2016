//
//  Tenta.cpp
//  final_sketch2
//
//  Created by Kris Li on 12/1/16.
//
//

#include "Tenta.hpp"

Tenta::Tenta(){
    step = 500;
    stepAdd = 500;
    res = 20;
    length = 1;
    width = 1;
    smooth = 2;
    
    angle = 0;
    angleCons = PI;
}

void Tenta::init(ofPoint _pos){
    pos = _pos;
}

void Tenta::update(ofPoint _link){
    pos = _link;
    
    hand.clear();
    
    for(int i=0; i< res; i++){
        float x, y, z;
        x = pos.x + sin(angle*i)*i*width + sin(angleCons)*i*width;
        y = pos.y + ofNoise(ofGetElapsedTimeMillis()/20);
        z = pos.z + i*i*length;
        hand.addVertex(x,y,z);
    }
    
    angle += PI/step;
    angleCons += PI/stepAdd;
    
    if(angle > 2*PI){
        angle = 0;
    }
}

void Tenta::draw(){
    
    ofSetColor(220, 88, 38);
    ofSetLineWidth(4);
    hand.draw();
    
    ofSetColor(255, 236, 14);
    handS = hand.getSmoothed(smooth);
    handS.draw();
}