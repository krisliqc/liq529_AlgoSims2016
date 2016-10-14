#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    Path path;
    
    num = 10;
    for(int i = 0; i< num; i++){
        Car temp;
        temp.init(path.start, path.end);
        cars.push_back(temp);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i< num; i++){
        cars[i].adjust();
        cars[i].update();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    path.draw();
    for(int i = 0; i< num; i++){
        cars[i].draw();
        
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
