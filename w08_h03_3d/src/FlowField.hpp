//
//  FlowField.hpp
//  w08_h03_3d
//
//  Created by Kris Li on 11/3/16.
//
//

#pragma once
#include "ofMain.h"

class FlowField {
public:
    FlowField();
    
    void setup(int _width, int _height, int _depth, int _res);
    void setPerlin();
    
    void draw();
    
    
    vector < vector<vector<ofVec2f> > > flowList;
    int width, height, depth, res;
    
private:
};
