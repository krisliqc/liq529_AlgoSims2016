//
//  Pixel.cpp
//  w08_h01_noise
//
//  Created by Kris Li on 11/2/16.
//
//

#include "Pixel.hpp"

Pixel::Pixel(){
    r = 0;
    g = 0;
    b = 0;
    pos = ofPoint(0,0);
    
    range = 250;
    ofRectMode(CENTER);
}

void Pixel::init(ofPoint _pos){
    pos = _pos;
}

void Pixel::getDist(ofPoint _rBall, ofPoint _gBall, ofPoint _bBall){
    rDist = ofDist(_rBall.x, _rBall.y, pos.x, pos.y);
    gDist = ofDist(_gBall.x, _gBall.y, pos.x, pos.y);
    bDist = ofDist(_bBall.x, _bBall.y, pos.x, pos.y);
}

void Pixel::update(){
    if(rDist < range){
        int rRange = ofMap(rDist, 0, range, 4, 1);
        r += rRange;
    }
    
    if(gDist < range){
        int gRange = ofMap(gDist, 0, range, 4, 1);
        g += gRange;
    }
    
    if(bDist < range){
        int bRange = ofMap(bDist, 0, range, 4, 1);
        b += bRange;
    }
    
    r --;
    g --;
    b --;
    
    if(r < 0){
        r = 0;
    }
    if(g < 0){
        g = 0;
    }
    if(b < 0){
        b = 0;
    }
}

void Pixel::draw(int _size){
    size = _size;
    ofSetColor(r, g, b);
    ofDrawRectangle(pos, size, size);
}