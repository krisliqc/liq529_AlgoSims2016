//
//  FlowField.cpp
//  w08_h03_3d
//
//  Created by Kris Li on 11/3/16.
//
//

#include "FlowField.hpp"

FlowField::FlowField() {
    
}

void FlowField::setup (int _width, int _height, int _depth, int _res){
    width = _width;
    height = _height;
    depth = _depth;
    res = _res;
    
    int cols = width/res;
    int rows = height/res;
    int layers = depth/res;
    
    for(int z = 0; z < layers; z++) {
        
        vector <vector<ofVec2f> > theList;
        flowList.push_back(theList);
    
        for(int y = 0; y < rows; y++){
        vector<ofVec2f> myList;
        flowList[z].push_back(myList);
        
            for(int x=0; x < cols; x++){
            ofVec2f dir(1,0);
            flowList[z][y].push_back(dir);
            
            }
        }
        
    }
}

void FlowField::setPerlin(){
    for(int z=0; z< flowList.size(); z++){
    for(int y=0; y< flowList[y].size(); y++){
        for(int x=0; x< flowList[x].size(); x++){
            float noise = ofMap(ofNoise(x*0.05, y*0.05, z*0.05), 0,1,0,2*PI);
            
            noise += ofGetElapsedTimeMillis()/100/PI;
            flowList[z][y][x].set(ofVec2f(cos(noise),sin(noise)));
        }
    }
    }
}

void FlowField::draw(){
    for(int z=0; z< flowList.size(); z++){
    for(int y=0; y< flowList[y].size(); y++){
        for(int x=0; x< flowList[x].size(); x++){
            
            ofPushMatrix();
            ofTranslate(x*res, y*res, z*res);
            ofDrawLine(ofPoint(0,0), flowList[z][y][x]*10);
            ofPopMatrix();
        }
    }
    }
}
