//
//  Bell.cpp
//  final_sketch2
//
//  Created by Kris Li on 12/1/16.
//
//

#include "Bell.hpp"

Bell::Bell(){
    gridScale = 15;
    size = 360/gridScale;
    
    radius = 200;
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
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            
            i1 = j + size * i;
            i2 = j+1 + size * i;
            i3 = j + size * (i+1);
            i4 = j+1 + size * (i+1);
            
            bell.addTriangle(i1, i2, i3);
            bell.addTriangle(i2, i3, i4);
        }
    }
}

void Bell::update(float rad1, float rad2){
    bell.clear();
    
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
    
    float time = ofGetElapsedTimef();
    //Now we want to loop through every vertex:
    //0, 1, 2, 3...
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            int index = j + size *i;
            
            ofPoint p = bell.getVertex(index);
            
            float perlin = ofNoise(j*0.1, i*0.1, time *0.5);
            radius = 175+ (perlin * 50);
            
            bell.setVertex(index, p.normalize()*radius);
            bell.setColor(index, ofColor(250, perlin*250, perlin*100));
            
        }
    }
}

void Bell::draw(){
    ofSetLineWidth(1);
    bell.drawWireframe();
//    bell.draw();
}