//
//  Jelly.cpp
//  final_sketch3
//
//  Created by Kris Li on 12/6/16.
//
//

#include "Jelly.hpp"

Jelly::Jelly(){
    pos = ofPoint(0,0,0);
}

void Jelly::init(ofPoint _pos, ofPoint _vel){
    pos = _pos;
    vel = _vel;
    acc.set(0,0,0);
    damp = 0.995;
    
    //bell
    bell.init(pos);
    arm1.init();
    
    //tentacles
    tentaSize = 12;
    
    float tentAngle = PI;
    
    for(int i = 0; i < tentaSize; i ++){
        Tenta temp;
        tenticles.push_back(temp);
        
        tenticles[i].init(ofPoint(pos.x + sin(tentAngle)*100, pos.y + cos(tentAngle)*100, 0));
        tentAngle += PI/6;
    }
}

void Jelly::update(float _rad1, float _rad2){
    
    //bell
    rad1 = _rad1;
    rad2 = _rad2;
    
    ofPoint mouse = ofPoint(ofGetMouseX(), ofGetMouseY());
    ofPoint dir = mouse - pos;
    
    vel += dir/100;
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    
    bell.update(rad1, rad2);
    
    //tentacles
//    for #i here, refer to "size" in Bell.cpp
//    for(int i = 0; i<18; i+2){
//        ofPoint temp = bell.getLink(i);
//        links.push_back(temp);
//    }
    
//    for(int i = 0; i < tentaSize; i ++){
//        tenticles[i].update(links[i]);
//    }
    
    
    arm1.update(pos);
    
    cout << "pos is " << pos <<endl;
}

void Jelly::draw(){
    ofSetColor(255, 0, 0);
    ofDrawCircle(pos, 10);
    
    bell.draw();
    
    //tentacles
    for(int i = 0; i < tentaSize; i ++){
        tenticles[i].draw();
    }
    
    //link test
    for(int i = 0; i < links.size(); i ++){
        ofDrawCircle(links[i], 10);
    }
    
    arm1.draw();
}

void Jelly::bound(){
    if( pos.x < 0.0 || pos.x > ofGetWidth()){
        pos.x -= vel.x;
        vel.x *= -1.0;
    }
    
    if( pos.y < 0.0|| pos.y > ofGetHeight()){
        pos.y -= vel.y;
        vel.y *= -1.0;
    }
    
    if( pos.z < -1000.0|| pos.z > 1000.0){
        pos.z -= vel.z;
        vel.z *= -1.0;
    }
}
