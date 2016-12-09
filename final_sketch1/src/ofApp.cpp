#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(true);
//    ofBackground(32,54,111);
    
    gui.setup();
    gui.add(step.setup("step", 500, 0, 720));
    gui.add(stepAdd.setup("step add", 500, 0, 720));
    gui.add(res.setup("res", 20, 0, 30));
    gui.add(length.setup("length", 1, 0, 3));
    gui.add(width.setup("width", 1, 0, 10));
    gui.add(smooth.setup("smooth", 2, 1, 5));
    
    
    pos.x = 200;
    pos.y = 200;
    angle = 0;
    angleCons = PI;
    
//    size = res;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    hand.clear();
    for(int i=0; i< res; i++){
        float x, y;
        perlin = ofNoise(ofGetElapsedTimeMillis()*0.0005, i*0.005);
        
//        perlin = ofNoise(ofGetElapsedTimeMillis()*0.0005);
        
//        float newAngle = ofMap(angle, 0, 360, , )
        x = pos.x + sin(angle*i*perlin)*i*width + sin(angleCons)*i*width;
        y = pos.y + i*i*length;
        
        hand.addVertex(x,y);
    }
    
//        angle += PI/720;
//        angleCons += PI/720;
    
    angle += PI/step;
    angleCons += PI/stepAdd;
    
    cout<<angle<<endl;
    
    if(angle > 2*PI){
        angle = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetColor(32,54,111);
//    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    
    gui.draw();
    
    ofSetColor(220, 88, 38);
    ofSetLineWidth(4);
    
    hand.draw();
    
    
    ofSetColor(255, 236, 14);
    handS = hand.getSmoothed(smooth);
    handS.draw();
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
