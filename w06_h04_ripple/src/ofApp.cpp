#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    numX = 50;
    numY = 50;
    
    for(int i=0; i<numX; i++){
        for (int j=0; j<numY; j++){
            
            float x = ofMap(i,0, numX, 0,ofGetWidth());
            float y = ofMap(j,0, numY, 0,ofGetHeight());
            
            Drop temp;
            drops.push_back(temp);
            drops[i].init(ofPoint(x,y), ofPoint(0,0));
            
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    int count = 0;
    
    for(int i = 0; i< numX; i++){
        for(int j = 0; j < numY; j++){
            
//            float x = ofMap(i,0, numX, 0,ofGetWidth());
//            float y = ofMap(j,0, numY, 0,ofGetHeight());
            
//            drops[count].resetForce();
            
            drops[count].addDamping();
            drops[count].update();
            
            count++;
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    cam.begin();
    
    ofBackground(200);
    ofSetColor(0);
    
    for(int i =0; i< drops.size(); i++){
//        ofColor thisColor = (0);
        
        drops[i].draw();
        
    }
    
//    cam.end();
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
