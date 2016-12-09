#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(rad1.setup("rad", PI/3, 0, 2*PI));
    gui.add(rad2.setup("rad", 2*PI/3, 0, 2*PI));
    
    ofPoint position = ofPoint(0, 0, 0);
    
    //bell
    bell.init(position);
    
    //tentacles
    tentaSize = 12;
    
    float tentAngle = PI;
    
    for(int i = 0; i < tentaSize; i ++){
        Tenta temp;
        tenticles.push_back(temp);
        
        tenticles[i].init(ofPoint(position.x + sin(tentAngle)*100, position.y + cos(tentAngle)*100, 0));
        tentAngle += PI/6;
    }
    
    //background
    lightSize = 5;
    
    for(int i = 0; i < lightSize; i ++){
        ofPoint temp;
        temp = ofPoint(ofRandomWidth(),ofRandomHeight());
        lights.push_back(temp);
    }
    step = 4;
    for(int i = 0; i < ofGetWidth(); i += step){
        for(int j = 0; j < ofGetHeight(); j += step/2){
            Pixel temp;
            ofPoint pos = ofPoint (i,j);
            temp.init(pos);
            pixels.push_back(temp);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //bell
    bell.update(rad1, rad2);
    
    //tentacles
    for(int i = 0; i < tentaSize; i ++){
        tenticles[i].update();
    }
    
    //background
    for(int i = 0; i < lights.size(); i ++){

        lights[i].x = ofNoise(ofGetElapsedTimef()/12-1000, i)*ofGetWidth();
        lights[i].y = ofNoise(ofGetElapsedTimef()/12+1000, i)*ofGetHeight();
    }
    
    for(int i = 0; i < pixels.size(); i += step){
        pixels[i].update(&lights);
        pixels[i].draw(step);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //background
    for(int i = 0; i < pixels.size(); i += step){
        pixels[i].draw(step*2);
    }
    
    for(int i = 0; i < lights.size(); i ++){
        ofSetColor(255,10);
        ofDrawCircle(lights[i], 3);
    }
    
    cam.begin();
    
    //bell
    bell.draw();

    //tentacles
    for(int i = 0; i < tentaSize; i ++){
        tenticles[i].draw();
    }
    
    cam.end();
    
    gui.draw();
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
