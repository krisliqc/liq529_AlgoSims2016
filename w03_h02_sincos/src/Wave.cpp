//
//  Wave.cpp
//  w03_h02_sincos
//
//  Created by Kris Li on 9/22/16.
//
//

#include "Wave.hpp"

Wave::Wave(){
    
    ofSetLineWidth(3);
}

void Wave::setup(){
    pos1 = ofPoint(0,100);
    pos2 = ofPoint(ofGetWidth(),100);
    
    vel = ofPoint(0, 5);
    
    h = 0;
}

void Wave::update(){
    
    pos1 = pos1 + vel;
    pos2 = pos2 - vel;
}

void Wave::draw(){
    
//    ofCurveVertices(<#const vector<ofPoint> &curvePoints#>)
    
//    for(int i=0; i<5;i++){
//        float x = ofGetWidth()/4*i;
//        float y = ofRandom(ofGetHeight())+sin(h);
//        h++;
//    }
//    ofPath();
//    ofpath.arc(0,100,ofGetWidth()*0.25, 100+sin(h),ofGetWidth()*0.5,100);
//    path.close();
//             
//    h++;
}
