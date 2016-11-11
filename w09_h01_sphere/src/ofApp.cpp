#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(wireframe.setup("Wireframe", false));
    
    gridScale = 10;
    size = 360/gridScale;
    
    radius = 300;
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            
            theta = ofMap(i, 0, size, 0, 2*PI);
            phi = ofMap(j, 0, size, 0, 2*PI);
            
            float a = radius*abs(cos(theta))*sin(phi);
            float b = radius*abs(cos(theta))*cos(phi);
            float c = radius*sin(theta);
            mesh.addVertex(ofPoint(a,b,c));
            
            //            mesh.addVertex(ofPoint(
            //                                   (x-gridWidth*0.5)*scale,
            //                                   (y-gridHeight*0.5)*scale,
            //                                   0));
            //            mesh.addColor(ofColor(0,0,0));
            
            //            points[i] = ofPoint(
            //                                radius[i]*cos(theta[i])*sin(phi[i]),
            //                                radius[i]*sin(phi[i])*sin(theta[i]),
            //                                radius[i]*cos(phi[i])
            //                                );
            mesh.addColor(ofColor(240,50,50));
        }
    }
    
    //create the triangle indices
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            
            i1 = j + size * i;
            i2 = j+1 + size * i;
            i3 = j + size * (i+1);
            i4 = j+1 + size * (i+1);
            
            mesh.addTriangle(i1, i2, i3);
            mesh.addTriangle(i2, i3, i4);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    
    //Now we want to loop through every vertex:
    //0, 1, 2, 3...
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            int index = j + size *i;
            
            ofPoint p = mesh.getVertex(index);
            
            float perlin = ofNoise(j*0.1, i*0.1, time *0.5);
            radius = 150+ (perlin * 150);
            
            mesh.setVertex(index, p.normalize()*radius);
            mesh.setColor(index, ofColor(250, perlin*250, perlin*100));
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(240, 220, 180);
    cam.begin();
    
    if(wireframe){
        mesh.drawWireframe();
    }else{
        mesh.draw();
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
//    mesh.drawWireframe();
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
