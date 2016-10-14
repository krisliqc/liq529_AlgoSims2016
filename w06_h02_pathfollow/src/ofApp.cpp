#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    begin = ofPoint(100,300);
    end = ofPoint(900,500);
    
    num = 10;
    for (int i=0;i< num; i++){
        Car temp;
        cars.push_back(temp);
        cars[i].init();
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0;i< num; i++){
        cars[i].follow(begin, end);
//        cars[i].seek(end);
        cars[i].update(begin, end);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(50);
    ofSetColor(0);
    ofSetLineWidth(3);
    ofDrawLine(begin, end);
    
    
    for (int i=0;i< num; i++){
        ofSetColor(255, 0, 0);
        cars[i].draw();
    }
    
//    path.setMode(ofPath::POLYLINES);
//    
//    path.arc( 50 + 20, 50 + 20, 40 + 10, 40 + 10, 0, 360);
//    path.close();
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
