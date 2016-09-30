#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofSetBackgroundAuto(false);
    ofBackground(0, 0, 50);
    ofEnableSmoothing();
    
    gui.setup();
    gui.add(radius.setup("radius", 200, 0, 400));
    
    angle =0;
    
    sunR = 120;
    a = 0;
    
    ofSetCircleResolution(60);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    angle += PI/60;
    
    sunR = 120 + 5*sin(a/3);
    a += 1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    //draw the sun
    ofSetColor(255,200,0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, sunR);
    
    
//    ofSetColor(230, 230, 0);
//    ofSetLineWidth(2);
//    ofDrawCircle(mouseX+ radius * cos(angle), mouseY+ radius * sin(angle), 10);
//    ofDrawCircle(100,100,50);
    
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
    //draw the moon
    
    cout << "click" << endl;
    ofSetColor(230, 230, 0);
    ofSetLineWidth(2);
    ofDrawCircle(mouseX+ radius * cos(angle), mouseY+ radius * sin(angle), 10);
    ofDrawCircle(100,100,50);

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
