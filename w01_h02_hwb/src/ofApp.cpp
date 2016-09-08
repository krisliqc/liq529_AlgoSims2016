#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    x1 = 50;
    y1 = 50;
    x2 = 100;
    y2 = 100;
    
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(grey);
    xPos = x1;
    yPos = y1;
    xPos2 = x2;
    yPos2 = y2;
    ofSetLineWidth(10);
    ofSetColor(0xffccff);
    ofDrawLine(xPos,yPos,xPos2,yPos2);
    
}
//
////--------------------------------------------------------------
//void ofApp::keyPressed(int key){

//}
//
////--------------------------------------------------------------
//void ofApp::keyReleased(int key){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseMoved(int x, int y ){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseDragged(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    grey +=20;
    if(step%2 == 0){
        x1 = ofGetMouseX();
        y1 = ofGetMouseY();
        
    } else {
        x2 = ofGetMouseX();
        y2 = ofGetMouseY();
    }
    step+=1;
}
//
////--------------------------------------------------------------
//void ofApp::mouseReleased(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseEntered(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseExited(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::windowResized(int w, int h){
//
//}
//
////--------------------------------------------------------------
//void ofApp::gotMessage(ofMessage msg){
//
//}
//
////--------------------------------------------------------------
//void ofApp::dragEvent(ofDragInfo dragInfo){
//
//}
