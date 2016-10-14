//
//  Path.cpp
//  w06_h02_pathfollow2
//
//  Created by Kris Li on 10/14/16.
//
//

#include "Path.hpp"

Path::Path(){
    radius = 40;
    start =  ofPoint(0,ofGetHeight()/3);
    end =  ofPoint(ofGetWidth(),2*ofGetHeight()/3);
}

void Path::draw(){
    ofSetLineWidth(radius*2);
    ofSetColor(0,100);
    ofDrawLine(start.x,start.y,end.x,end.y);
    
    ofSetLineWidth(1);
    ofSetColor(0);
    ofDrawLine(start.x,start.y,end.x,end.y);
    
    
}