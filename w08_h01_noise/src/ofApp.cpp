#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
//    ofSetBackgroundAuto(false);
    
    rBall = ofPoint(ofRandomWidth(),ofRandomHeight());
    gBall = ofPoint(ofRandomWidth(),ofRandomHeight());
    bBall = ofPoint(ofRandomWidth(),ofRandomHeight());
    
    step = 5;
    
    for(int i = 0; i < ofGetWidth(); i += step){
        for(int j = 0; j < ofGetHeight(); j += step){
            Pixel temp;
            ofPoint pos = ofPoint (i,j);
            temp.init(pos);
            pixels.push_back(temp);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    rBall.x = ofNoise(ofGetElapsedTimef()/4+1000)*ofGetWidth();
    
    cout << rBall.x << endl;
    rBall.y = ofNoise(ofGetElapsedTimef()/4)*ofGetHeight();
    
    gBall.x = ofNoise(ofGetElapsedTimef()/4-1000)*ofGetWidth();
    gBall.y = ofNoise(ofGetElapsedTimef()/4+1000)*ofGetHeight();
    
    bBall.x = ofNoise(ofGetElapsedTimef()/4+2500)*ofGetWidth();
    bBall.y = ofNoise(ofGetElapsedTimef()/4+500)*ofGetHeight();
    
    
    for(int i = 0; i < pixels.size(); i += step){
        pixels[i].getDist(rBall, gBall, bBall);
        pixels[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < pixels.size(); i += step){
        pixels[i].draw(step*3);
    }
    
    ofSetColor(255, 0, 0);
    ofDrawEllipse(rBall, 10, 10);
    ofSetColor(0, 255, 0);
    ofDrawEllipse(gBall, 10, 10);
    ofSetColor(0, 0, 255);
    ofDrawEllipse(bBall, 10, 10);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'r'){
        rBall = ofPoint(ofGetMouseX(),ofGetMouseY());
    } else if (key == 'g'){
        gBall = ofPoint(ofGetMouseX(),ofGetMouseY());
    } else if (key == 'b'){
        bBall = ofPoint(ofGetMouseX(),ofGetMouseY());
    }
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
