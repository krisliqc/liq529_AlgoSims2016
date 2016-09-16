#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    

    for(int i = 0; i< 200; i++){
        
        MyBall temp;
        manyBalls.push_back(temp);
    }
    
    ofSetBackgroundColor(0);
    step = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
//    myBall.update();
    
    for(int i = 0; i< 200; i++){
        
        manyBalls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(200 , 100, 150);
//    myBall.draw();
    
// to blink
    for(int i = 0; i< 200; i++){
        
//        if(mouse == true){
        
            ofSetColor(i,i/2,200);
            
//        } else {
        
//            ofSetColor(0,0,50);
//        }
        manyBalls[i].draw();
    }

    step+=1;
    
//    cout<<ofGetFrameRate()<<endl;
    cout<<ofGetElapsedTimef()<<endl;
    
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
