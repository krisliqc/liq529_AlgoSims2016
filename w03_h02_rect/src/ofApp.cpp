#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    a = 0;
    color = ofColor(a, a, 200);
}

//--------------------------------------------------------------
void ofApp::update(){
    a += 0.05;
    r = ofRandom(100,200);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()*0.3, ofGetHeight()*0.5);
    ofEnableSmoothing();
    p1 = ofPoint(0 + sin(a)*r,0 +cos(a)*r);
    p2 = ofPoint(300+ sin(2*a)*r,0+cos(2*a)*r);
    p3 = ofPoint(150+ sin(0.5*a)*r,200 +cos(0.5*a)*r);
    ofSetColor(color);
    ofDrawTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
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
