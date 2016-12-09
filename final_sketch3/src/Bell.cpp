//
//  Bell.cpp
//  final_sketch2
//
//  Created by Kris Li on 12/1/16.
//
//

#include "Bell.hpp"

Bell::Bell(){
    gridScale = 10;
    size = 360/gridScale;
    
    radius = 100;
    angle = 0;
}

void Bell::init(ofPoint pos){
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            
            theta = ofMap(j, 0, size, 0, 2*PI);
            phi = ofMap(i, 0, size, 0, 2*PI);
            
            float a = radius*abs(cos(theta))*sin(phi);
            float b = radius*abs(cos(theta))*cos(phi);
            float c = radius*sin(theta);
            bell.addVertex(ofPoint(a,b,c));
            bell.addColor(ofColor(252,244,162));
        }
    }
    
    //create the triangle indices
    for(int i = 0; i <size-1; i++){
        for(int j = 0; j <size-1; j++){
            
            i1 = j + size * i;
            i2 = j+1 + size * i;
            i3 = j + size * (i+1);
            i4 = j+1 + size * (i+1);
            
            bell.addTriangle(i1, i2, i3);
            bell.addTriangle(i2, i3, i4);
        }
    }
}

void Bell::update(float _rad1, float _rad2){
    bell.clear();
    
    rad1 = _rad1;
    rad2 = _rad2;
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            
            theta = ofMap(j, 0, size, rad1, rad2);
            phi = ofMap(i, 0, size, 0, 2*PI);
            
            float a = radius*abs(cos(theta))*sin(phi);
            float b = radius*abs(cos(theta))*cos(phi);
            float c = radius*sin(theta);
            bell.addVertex(ofPoint(a,b,c));
            bell.addColor(ofColor(252,244,162));
        }
    }
    
    //create the triangle indices
    for(int i = 0; i <size-1; i++){
        for(int j = 0; j <size-1; j++){
            
            i1 = j + size * i;
            i2 = j+1 + size * i;
            i3 = j + size * (i+1);
            i4 = j+1 + size * (i+1);
            
            bell.addTriangle(i1, i2, i3);
            bell.addTriangle(i2, i3, i4);
        }
    }
    
//    for(int i = 0; i <size-1; i++){
//        i1 = size * (1 + i);
//        i2 = size * i +1;
//        i3 = size * (2 + i);
//        i4 = size * (i + 1) + 1;
//        
//        bell.addTriangle(i1, i2, i3);
//        bell.addTriangle(i2, i3, i4);
//        
//    }
//    
//    
//    bell.addTriangle(684, 649, 720);
//    bell.addTriangle(649, 720, 685);
    
    float time = ofGetElapsedTimef();
    
    //Now we want to loop through every vertex:
    //0, 1, 2, 3...
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            int index = j + size *i;
            
            ofPoint p = bell.getVertex(index);
            
            float perlin = ofNoise(j*0.05, time *0.5);
//            radius = 175+ (perlin * 100);
            radius = 200 + sin(perlin)*50;
            
            bell.setVertex(index, p.normalize()*radius);
            bell.setColor(index, ofColor(250, perlin*250, perlin*100));
            
        }
    }
    
    angle += PI/72;
}


ofPoint Bell::getLink(int _loop){
    
    int loop = _loop;
    
    //this is getting the links
        theta = rad2;
        phi = ofMap(loop, 0, size, 0, 2*PI);
        float a = radius*abs(cos(theta))*sin(phi);
        float b = radius*abs(cos(theta))*cos(phi);
        float c = radius*sin(theta);
        ofPoint linkReturn = ofPoint(a,b,c);
    
    return linkReturn;
    //---------------
    
}

void Bell::draw(){
    ofSetLineWidth(1);
    bell.drawWireframe();
//    bell.draw();
}





