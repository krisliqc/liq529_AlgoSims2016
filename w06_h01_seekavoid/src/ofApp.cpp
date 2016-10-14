#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    num = 20;
    
    for(int i=0; i<num; i++){
        
        Particle temp;
        cars.push_back(temp);
        cars[i].setInit(ofGetWindowSize() / 2);
    }
    
    dest = ofPoint(300,300);
    
    r = 15;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0; i<num; i++){
        
        cars[i].update(cars);
        cars[i].seek(dest);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 100, 200);
    
    for(int i=0; i<num; i++){
        cars[i].draw();
        
    }
    
    ofSetColor(255,255, 0);
    
    ofDrawCircle(dest, r);
    
    r *= 0.99;
    
    if(r < 0){
        r = 0;
    }
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
    r = 15;
    dest = ofPoint(ofGetMouseX(),ofGetMouseY());
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
