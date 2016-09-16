//reference: class work
//Regina Flores 09/13/16


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(240, 200, 240);
    
    ofSetVerticalSync(true); //?
//    ofEnableAlphaBlending();
    
    myMover.pos.x = 200;
    myMover.pos.y = 200;
}

//--------------------------------------------------------------
void ofApp::update(){
    myMover.xenoToPoint(mouseX, mouseY);
    theta = ofRadToDeg(atan2(mouseY-ofGetHeight()/2,mouseX-ofGetWidth()/2));
    cout<<  theta  <<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myMover.draw();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(90+theta);
    ofDrawTriangle(0, -50, 20, 0, -20, 0);
    ofPopMatrix();
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
