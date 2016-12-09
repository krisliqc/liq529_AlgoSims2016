//
//  Pixel.cpp
//  w08_h01_noise
//
//  Created by Kris Li on 11/2/16.
//
//

#include "Pixel.hpp"

Pixel::Pixel(){
    r = 32;
    g = 54;
    b = 111;
    pos = ofPoint(0,0);
    
    range = 75;
    ofRectMode(CORNER);
}

void Pixel::init(ofPoint _pos){
    pos = _pos;
}

void Pixel::update(vector<ofPoint> *lights){
    
    for(int i = 0; i < lights->size(); i++){
        dist = ofDist((*lights)[i].x, (*lights)[i].y, pos.x, pos.y);
//        cout<<dist<<endl;
        if(dist < range){
            float lightUp = ofMap(dist, 0, range, 2, 1);
            r +=lightUp;
            g +=lightUp;
            b +=lightUp;
        }
    }
    
    
    r -= 1;
    g -= 1;
    b -= 1;
    
    if(r < 32){
        r = 32;
    }
    if(g < 54){
        g = 54;
    }
    if(b < 111){
        b = 111;
    }
}

void Pixel::draw(int _size){
    size = _size;
    ofSetColor(r, g, b);
    ofDrawRectangle(pos, size, size);
}