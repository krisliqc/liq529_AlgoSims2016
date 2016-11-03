//
//  FlowField.hpp
//  w08_h02_flowfield
//
//  Created by Kris Li on 11/3/16.
//
//

#pragma once
#include "ofMain.h"

class FlowField {
public:
    FlowField();
    
    void setup(int _width, int _height, int _res);
    void setPerlin();
    void setAttract();
    void setRepel();
    void setRotate();
    
    void draw();
    
//    void drawVector(const ofVec3f &start, const ofVec3f &end, float headLength = 0.2f, float headRadius = 0.05f);
//    void drawVectorAt(const ofVec2f &vec, const ofVec2f &pos);
    
    vector<vector<ofVec2f> > flowList;
    int width, height, res;
    
private:
};
