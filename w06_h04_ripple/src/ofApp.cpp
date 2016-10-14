#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    numX = 30;
    numY = 30;
    
    for(int i=0; i<numX; i++){
        for (int j=0; j<numY; j++){
            
            float x = ofMap(i,0, numX, 0,ofGetWidth());
            float y = ofMap(j,0, numY, 0,ofGetHeight());
            
            Drop temp;
            temp.init(ofPoint(x,y), ofPoint(0,0));
            drops.push_back(temp);
            
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i< drops.size(); i++){
            
            drops[i].addDamping();
            drops[i].update();
            
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    cam.begin();
    
    ofBackground(50);
//    ofSetColor(0);
    
    for(int i =0; i< drops.size(); i++){
        ofSetColor(50+i/2,50+i/4,80+i/4);
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
    for(int i =0; i< drops.size(); i++){
        
        ofPoint click = ofPoint(ofGetMouseX(),ofGetMouseY());
        
        drops[i].horizontal(click);
        
    }
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
