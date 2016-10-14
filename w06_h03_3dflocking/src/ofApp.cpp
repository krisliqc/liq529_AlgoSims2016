#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    //create the particles
    num = 100;
    
    for(int i =0; i < num; i++){
        
        Particle p;
        birds.push_back(p);
        birds[i].init();
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < num; i++){
        
        birds[i].update(&birds);
        birds[i].bounding();
        birds[i].avoid();
        birds[i].seek();
        
    }
    
    float x1 = birds[1].pos.x;
    float y1 = birds[1].pos.y;
    float z1 = birds[1].pos.z;
    cout << "x1: " << z1 << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    ofBackground(0);
    ofSetColor(255);
    
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    for(int i = 0; i < num; i++){
        birds[i].draw();
    }
    
    cam.end();
    
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
