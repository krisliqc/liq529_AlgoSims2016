#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
//    ofBackground(220,120,160);
    x = 0;
    y = 0;
    
    radius = 10;
    
    h = PI;
    w = PI;
    
    gui.setup();
    gui.add(factor1.setup("factor1",42,1,100));
    gui.add(factor2.setup("factor2",58,1,100));
//    gui.add(radius.setup("radius",10,5,30));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(220, 120, 160, 90);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
//    ofDrawRectangle(, , , )
    
    gui.draw();
    
    ofSetColor(255,200);
    ofDrawEllipse(sin(x)*radius+ofGetWidth()/2,cos(y)*radius+ofGetHeight()/2,10+60*sin(w),10+60*sin(h));
    
    radius += 0.2;
    
    w += PI/72;
    h += PI/90;
    
    x += PI/factor1;
    y += PI/factor2;
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
