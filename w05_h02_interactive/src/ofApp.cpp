#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    //    gui.add(filled.setup("fill", true));
    gui.add(gravity.setup("Gravity", 1, 0,10));
    gui.add(k.setup("Spring k", 0.2, 0,1));
    gui.add(radius.setup("Ball field", 50, 0,100));
    
    ofBackground(200,250,250);
    
    for(int i =0; i < 5; i++){
        
        particles[i].setInit(ofPoint(ofRandom(ofGetWidth()),
                                     ofRandom(ofGetHeight())));
    }
    
    particles[0].bFix = true;
    
    //spring array
    springs[0].set(&particles[0], &particles[1], k);
    springs[0].restDist = 40;
    springs[1].set(&particles[1], &particles[2], k);
    springs[1].restDist = 40;
    springs[2].set(&particles[2], &particles[3], k);
    springs[2].restDist = 40;
    springs[3].set(&particles[3], &particles[4], k);
    springs[3].restDist = 40;
    
    
    ball = ofPoint(0, ofGetHeight()/2);
    ballVel = ofPoint(10,10);
}

//--------------------------------------------------------------
void ofApp::update(){
    particles[0].pos.set(ofGetWidth()/2, 100);
    
    for(int i =0; i< 4; i++){
        springs[i].update();
    }
    
    for(int i = 0; i < 5; i++){
        particles[i].addForce(ofPoint(0,0.1));
        particles[i].addGravity(ofPoint(0,gravity));
        particles[i].update();
        particles[i].bounding();
    }
    
    //the disturbance
    ball += ballVel;
    
    //bounding for the ball
    if(ball.x > ofGetWidth() || ball.x < 0){
        ballVel.x *= -1;
    }
    if(ball.y > ofGetHeight() || ball.y < 0){
        ballVel.y *= -1;
    }
    
    //effect
    
    for(int i =0; i < 5; i++){
        if(ofDist(ball.x, ball.y,particles[i].pos.x, particles[i].pos.y)< radius){
            ofPoint f = ofPoint(ball.x - particles[i].pos.x, ball.y - particles[i].pos.y);
            particles[i].reverse(f);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i =0; i< 4; i++){
        springs[i].draw();
    }
    
    for(int i = 0; i < 5; i++){
        
        particles[i].draw();
    }
    
    //    if(filled){
    //        ofFill();
    //    }else{
    //        ofNoFill();
    //    }
    
    
    ofSetColor(150,150,30);
    ofDrawCircle(ball, 10);
    
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
