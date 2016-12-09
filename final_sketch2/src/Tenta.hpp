//
//  Tenta.hpp
//  final_sketch2
//
//  Created by Kris Li on 12/1/16.
//
//

#pragma once
#include "ofMain.h"

class Tenta {
public:
    
    Tenta();
    void init(ofPoint pos);
    void update();
    void draw();
    
    
    ofPolyline hand;
    ofPolyline handS;
    ofPoint pos;
    
private:
    
    int size;
    float angle;
    float angleCons;
    
    int res;
    float length;
    float width;
    int smooth;
    float step;
    float stepAdd;
    
};