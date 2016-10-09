//
//  Spring.hpp
//  w05_h01_strings
//
//  Created by Kris Li on 10/5/16.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class Spring{
    
public:
    
    Spring();
    void set(Particle * _A, Particle * _B);
    void update();
    void draw();
    
    float k;
    float restDist;
    
    
    Particle * A;
    Particle * B;
    
    
    
};