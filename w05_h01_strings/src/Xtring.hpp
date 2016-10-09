//
//  Xtring.hpp
//  w05_h01_strings
//
//  Created by Kris Li on 10/5/16.
//
//

#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Spring.hpp"

class Xtring {
public:
    
    Xtring();
    
//    void setInit(ofPoint _pos);

    void setInit();
    void bound();
    void update();
    void draw();
    
    
    Particle particles[3];
    Spring springs[2];
    
    //private:
    ofPoint pos;
    ofPoint vel;
    
    ofPoint ball1;
    ofPoint ball2;
};