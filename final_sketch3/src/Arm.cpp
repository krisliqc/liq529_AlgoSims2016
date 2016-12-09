//
//  Arm.cpp
//  final_sketch3
//
//  Created by Kris Li on 12/6/16.
//
//

#include "Arm.hpp"

Arm::Arm(){
    pos = ofPoint (0,0,0);
}

void Arm::init(){
    for(int i = 0; i < anchorSize; i++){
        ofPoint temp;
        temp = ofPoint(0,0,0);
        anchors.push_back(temp);
    }
    
    for(int i = 0; i < anchorSize; i++){
        ofPoint temp2;
        temp2 = ofPoint(0,0,0);
        hairs.push_back(temp2);
    }
}

void Arm::update(ofPoint _pos){
    ofPoint current;
    current = _pos;
//    anchors.push_back(_pos);
    int loopN = anchors.size()-1;
    
    for(int i = 0; i < loopN; i++){
        anchors[i] = anchors[i+1];
    }
    anchors[anchorSize] = current;
    
    
    noise = ofNoise(ofGetElapsedTimeMillis());
//    for(int i = 0; i < anchorSize; i++){
//        hairs[i].x = anchors[i].x + noise * 10 - 10;
//        hairs[i].y = anchors[i].y + noise * 5 - 5;
//        hairs[i].z = anchors[i].z + noise * 10 - 5;
//    }
    
    if (anchors.size() > anchorSize){
        anchors.erase(anchors.begin());
    }
    
    float x1 = anchors[0].x;
    cout << "the last value is: " << x1 << endl;
    float y1 = anchors[0].y;
    cout << "the last y value is: " << y1 << endl;
    float y2 = anchors[1].y;
    cout << "the last y value is: " << y2 << endl;
    float y3 = anchors[2].y;
    cout << "the last y value is: " << y3 << endl;
//    cout << "the first value is: " <<current.x << endl;
}

void Arm::draw(){
    
//    ofNoFill();
    ofSetColor(100, 50, 200);
    
    ofDrawCircle(anchors[1], 10);
    
//    ofBeginShape();
//    
//    for (int i = 0; i < anchors.size(); i++){
//        ofVertex(anchors[i].x + cos(ofGetElapsedTimef()*10+1*i)*10, anchors[i].y );
//    }
//    ofEndShape();
    
    ofFill();
    ofSetLineWidth(2);
    
    for (int i = 0; i < anchorSize; i++){
        ofDrawCircle(anchors[i].x, anchors[i].y, 5);
    }
    
//    ofBeginShape();
//    for (int i = 0; i < anchors.size(); i++){
//        ofVertex(anchors[i].x, anchors[i].y);
//    }
//    ofEndShape();
    
//    ofBeginShape();
//        ofVertex(100,200);
//        ofVertex(200,100);
//        ofVertex(300,100);
//    ofEndShape();
    
//    ofSetColor(255);
//    for (int i = 0; i < anchors.size(); i++){
//        ofDrawLine(anchors[i], hairs[i]);
//    }
}

