//
//  MyBall.cpp
//  BouncingBall
//
//  Created by Kris Li, reference to Regina Flores on 9/14/16.
//
//

#include "ball.hpp"

//Constructor
MyBall::MyBall(){
    
    //Dot Notation:
    velocity.x = ofRandom(0,1);
    velocity.y = ofRandom(0,1);
    
    //generate from random point on screen
    position.x = ofRandom(0,1)*ofGetWidth();
    position.y = ofRandom(0,1)*ofGetHeight();
}

void MyBall::update(){
    
    position.x += velocity.x *3;
    position.y += velocity.y *3;
    
    
    //mouse condition
    
    dist = ofDist(ofGetMouseX(), ofGetMouseY(), position.x, position.y);
    
    if(dist < 100){
        velocity.x +=ofRandom(-0.3,0.3);
        velocity.y +=ofRandom(-0.3,0.3);
        
        
        //these two made the particles stop...i thought they are suppose to go in an opposite direction
//        velocity.x = velocity.x * -1;
//        velocity.y = velocity.y * -1;
        
        //check the ones that have already been modified and add them to an array and don't check them again
        
    }
    
// gradually slow down?
    velocity.x = velocity.x * 0.995;
    velocity.y = velocity.y * 0.995;
    
    //Bounding Conditions
    if(position.x < 0 || position.x > ofGetWidth()){
        velocity.x = velocity.x * -1;
        
    }
    
    if( position.y < 0 || position.y > ofGetHeight()){
        velocity.y = velocity.y * -1;
    }
    
}

void MyBall::draw(){
    //    ofSetColor(255, 0, 0);
    ofDrawCircle(position, 5);
}



