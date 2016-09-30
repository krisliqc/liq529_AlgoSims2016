#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    gui.setup();
    gui.add(size.setup("Blur radius", 20, 10,30));
    
    
    original.load("wave.png");
    
    //    The types of images can be OF_IMAGE_COLOR, OF_IMAGE_COLOR_ALPHA or OF_IMAGE_GRAYSCALE.
    
//    final.allocate(original.getWidth(), original.getHeight(), OF_IMAGE_COLOR);
//    
//    int w = original.getWidth();
//    int h = original.getHeight();
    
//    for (int i = 0; i < w; i++){
//        
//        for (int j = 0; j < h; j++){
//            
//            ofColor orig = original.getColor(i,j);
//            
//            
//            
//            final.setColor(i,j,lineOfPixels[j]);
//            
//        }
//        
//    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(50);
    
    original.draw(0,0);
    ofRectMode(CENTER);
//    
//    ofPushMatrix();
//    ofTranslate(0, 0);
    
    
        int w = original.getWidth();
        int h = original.getHeight();

    
    for (int i = 0; i < w; i+=size){
        
        for (int j = 0; j < h; j+=size){
            ofColor orig = original.getColor(i,j);
            ofSetColor(orig);
            ofDrawRectRounded(i, j, size, size, size*0.25);
            cout << "drawing" << endl;
        }
    }
//    ofPopMatrix();
    
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
