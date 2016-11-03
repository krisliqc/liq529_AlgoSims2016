//
//  FlowField.cpp
//  w08_h02_flowfield
//
//  Created by Kris Li on 11/3/16.
//
//

#include "FlowField.hpp"

FlowField::FlowField() {
    
}

void FlowField::setup (int _width, int _height, int _res){
    width = _width;
    height = _height;
    res = _res;
    
    int cols = width/res;
    int rows = height/res;
    
    for(int y = 0; y < rows; y++){
        vector<ofVec2f> myList;
        flowList.push_back(myList);
        
        for(int x=0; x < cols; x++){
            ofVec2f dir(1,0);
            flowList[y].push_back(dir);
            
        }
    }
}

void FlowField::setPerlin(){
    for(int y=0; y< flowList.size(); y++){
        for(int x=0; x< flowList[y].size(); x++){
            float noise = ofMap(ofNoise(x*0.05, y *0.05), 0,1,0,2*PI);
            flowList[y][x].set(ofVec2f(cos(noise),sin(noise)));
        }
    }
    
}

void FlowField::setAttract(){
    for(int y=0; y< flowList.size(); y++){
        for(int x=0; x< flowList[y].size(); x++){
            ofPoint pos = ofPoint(x*res, y*res);
            ofPoint dir = (ofGetMouseX(),ofGetMouseY()) - pos;
            dir.normalize();
            
            flowList[y][x].set(dir);
        }
    }
    
}

void FlowField::setRepel(){
    for(int y=0; y< flowList.size(); y++){
        for(int x=0; x< flowList[y].size(); x++){
            ofPoint pos = ofPoint(x*res, y*res);
            ofPoint dir = (ofGetMouseX(),ofGetMouseY()) - pos;
            dir.normalize()*6;
            dir = dir.getRotated(0, 0, 90);
            flowList[y][x].set(dir);
        }
    }
    
}

void FlowField::setRotate(){
    
//    float deg;
    
    for(int y=0; y< flowList.size(); y++){
        for(int x=0; x< flowList[y].size(); x++){
            
            float noise = ofMap(ofNoise(x*0.05, y *0.05), 0,1,0,2*PI);
            noise += ofGetElapsedTimeMillis()/100/PI;
            ofPoint angle = ofVec2f(cos(noise),sin(noise));
            flowList[y][x].set(angle);
            
//            flowList[y][x].set(ofPoint(1,0)); //testing
        }
    }
//    deg += PI/72;
}

void FlowField::draw(){
    for(int y=0; y< flowList.size(); y++){
        for(int x=0; x< flowList[y].size(); x++){
            
            ofPushMatrix();
            ofTranslate(x*res, y*res);
            ofDrawLine(ofPoint(0,0), flowList[y][x]*10);
            ofPopMatrix();
//            drawVectorAt(flowList[y][x], np);
        }
    }
}

//void FlowField::drawVectorAt(const ofVec2f &vec, const ofVec2f &pos){
//    ofVec2f np = pos - (vec.getNormalized())*5.0;
//    drawVector(np, np + vec.getNormalized() * 10.0, 5,3);
//}