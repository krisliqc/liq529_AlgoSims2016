#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofGetBackgroundAuto();
    
    ofBackground(32,54,111);
    ofBackground(0);
    
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    
    res = 500;
    radius = 200;
    
    height = radius*0.05;
    loop = 24;
    
    pct = 0.6;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    circle.clear();
    speed = ofGetElapsedTimef()*0.5;
    
    for(int i = 0; i < res; i++){
        angle = ofMap(i, 0, res, 0, 2*PI);
        rise = height*sin((angle+speed)*loop);
        
        float x, y;
        
        if(i < res*pct){
                        x = cos(angle)*(radius+rise);
                        y = sin(angle)*(radius+rise);
//            x = cos(angle)*(radius+rise);
//            y = sin(angle)*(radius+rise);
        } else {
            x = cos(angle)*(radius);
            y = sin(angle)*(radius);
        }
        
        circle.addVertex(ofPoint(x,y));
    }
    
//    circle.close();
//    circle = circle.getSmoothed(10);
    
    cout << speed <<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(32,54,111);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(220,88,38);
    ofSetLineWidth(4);
    ofTranslate(pos);
    
    circle.draw();
    
    ofSetColor(255, 0, 0);
    ofDrawEllipse(ofGetMouseX(), ofGetMouseY(), 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
