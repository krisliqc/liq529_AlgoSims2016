//
//  mover.cpp
//  w02_h03_atan2
//
//  Created by Kris Li, reference to Regina Flores on 9/14/16.
//
//

#include "mover.hpp"

mover:: mover(){
    
    catchUpSpeed = 0.1;
}


void mover::draw(){
    
    ofFill();
    ofSetColor(255);
    ofDrawRectangle(pos.x, pos.y, 50,50);
}

void mover::xenoToPoint(float catchX, float catchY){
    //Xeno formula:
    //myPos = (1-pct) * myPos + pct * targetPos
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) *pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) *pos.y;
    
}
