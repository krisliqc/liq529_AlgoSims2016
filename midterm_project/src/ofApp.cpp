#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(0,64,86);
    ofSetCircleResolution(60);
    ofSetSmoothLighting(true);
    ofEnableSmoothing();
    
    
    //gui
    gui.setup();
    gui.add(x.setup("x",-1100,-10000,10000));
    gui.add(y.setup("y",-200,-10000,10000));
    gui.add(z.setup("z",-500,-1000,1000));
    gui.add(xAngle.setup("sky angle",270,0,360));
    gui.add(rippleM.setup("ripple shape",25,0,100));
    gui.add(wave.setup("wave shape",288,0,300));
    gui.add(area.setup("area",150, 100,500));
    gui.add(damping.setup("damping",0.15, 0,1));
    gui.add(repulsion.setup("repulsion",0.05, 0,1));
    
    
    //drop
    numX = 30;
    numY = 30;
    
    for(int i=0; i<numX; i++){
        for (int j=0; j<numY; j++){
            
            float x = ofMap(i,0, numX, 0,ofGetWidth());
            float y = ofMap(j,0, numY, 0,ofGetHeight());
            
            Drop temp;
            temp.init(ofPoint(x+numX/2,y+numY/2), ofPoint(0,0), damping);
            drops.push_back(temp);
        }
    }
    
    //boat
    boat1.init(ofGetWindowSize()/2, ofPoint(-10,10));
    boat2.init(ofGetWindowSize()/2+(200,200), ofPoint(5,-15));
    
    dest1 = ofPoint(300,300);
    dest2 = ofPoint(500,500);
    r= 15;
    
    //cam
    cam.rotate(245, cam.getSideDir());
    cam.setDistance(650);
    
    sun.setDiffuseColor(ofColor(255,255,255));
    sun.setSpecularColor(ofColor(255));
    
    sky.load("sky.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //ripple
    for(int i = 0; i< ripples.size(); i++){
        ripples[i].update(&ripples, wave);
    }
    
    
    //drop
    for(int i = 0; i< drops.size(); i++){
        
        drops[i].addDamping();
        drops[i].update();
    }
    
    
    //boat
    boat1.update();
    boat2.update();
    boat1.seek(dest1);
    boat2.seek(dest2);
    float area = 200;
    
    if(boat1.getPosition().distance(boat2.getPosition())<area){
        boat1.addRepulsionForce(boat2.getPosition(), area, repulsion);
        boat2.addRepulsionForce(boat1.getPosition(), area, repulsion);
    }
    
    //cam
    sun.setPosition(sin(-1000+ofGetElapsedTimef())*500, cos(-1000+ofGetElapsedTimef())*200, -1500);
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetColor(34,83,120,90);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    
    
    gui.draw();
    cam.begin();
    
    
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    
    
    
    for(int i = 0; i< ripples.size(); i++){
        ripples[i].draw(rippleM);
    }
    
    for(int i =0; i< drops.size(); i++){
        drops[i].draw();
    }
    
    
    boat1.draw();
    boat2.draw();
    ofDrawCircle(dest1, r);
    ofDrawCircle(dest2, r);
    r *= 0.99;
    if(r < 0){
        r = 0;
    }
    
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateX(xAngle);
    sky.draw(x,y,z, 2000, 1000);
    ofPopMatrix();
    
//    ofEnableLighting();
//    sun.enable();
    
    
    cam.end();
    
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
    
    //ripple
    Ripple temp;
    temp.init(ofPoint(ofGetMouseX(),ofGetMouseY()));
    ripples.push_back(temp);
    
    
    //drop
    for(int i =0; i< drops.size(); i++){
        
        ofPoint click = ofPoint(ofGetMouseX(),ofGetMouseY());
        drops[i].horizontal(click, area);
    }
    
    //boat
    ofSetColor(200,200,0);
    if(step%2 == 0){
        dest1 = ofPoint(ofGetMouseX(),ofGetMouseY());
    } else {
        dest2 = ofPoint(ofGetMouseX(),ofGetMouseY());
    }
    step+=1;
    r = 15;
//    dest = ofPoint(ofGetMouseX(),ofGetMouseY());
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
