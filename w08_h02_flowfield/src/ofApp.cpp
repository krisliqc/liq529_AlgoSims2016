#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myField.setup(ofGetWidth(),ofGetHeight(),20);
    
    myField.setPerlin();
    ofBackground(0);
    mode = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(mode == 1){
        myField.setAttract();
    }else if(mode == 2){
        myField.setRepel();
    }else if(mode == 3){
        myField.setRotate();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    myField.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1'){
        mode = 1;
//        myField.setAttract();
    }else if(key =='2'){
        mode = 2;
//        myField.setRepel();
    }else if(key =='3'){
        mode = 3;
        //        myField.setRepel();
    }
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
