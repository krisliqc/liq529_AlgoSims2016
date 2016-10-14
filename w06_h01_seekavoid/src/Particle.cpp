#include "Particle.h"

Particle::Particle() {
    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;
    pos.z = 0.0;
    
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    damp = 0.95;
    radius = 5;
    
    fish.load("fish.png");
}

void Particle::setInit(ofPoint _pos, ofPoint _vel){
    pos = _pos;
    vel = _vel;
    acc.set(0,0,0);
    
}

ofPoint Particle::getPosition(){
    return pos;
}

float Particle::getRadius(){
    return radius;
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}

//void Particle::addRepulsionForce(ofPoint _pos, float _rad, float _scale){
//    
//    ofPoint diff = _pos - pos;
//    if( diff.length() < _rad ){
//        diff *= 1.0-diff.length()/_rad;// PRO way
//        addForce(-diff*_scale);
//    }
//}

//void Particle::addAttractionForce(ofPoint _pos, float _rad, float _scale){
//    ofPoint diff = _pos - pos;
//    if( diff.length() < _rad ){
//        diff *= 1.0-diff.length()/_rad;
//        addForce(diff*_scale);
//    }
//}

void Particle::seek( ofPoint dest ) {
    float maxSpeed = 10.0;
    float maxForce = 0.4;
    
    float slowDownRadius = 200.0;
    
    ofPoint desired = dest - pos;
    
    if( desired.length() < slowDownRadius ){
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        
        desired.normalize();
        desired *= newMag;
    }else{
        desired.normalize();
        desired *= maxSpeed;
    }
    
    ofPoint steer = desired - vel;
    steer.limit( maxForce );
    
    
    
    float dist_dest;
    dist_dest = ofDist(dest.x,dest.y, pos.x,pos.y);
    if(dist_dest < 20){
        steer = steer/10;
    }
    
    addForce( steer );
    
    
}

ofPoint Particle::separation(vector<Particle> &particles){
    
    ofPoint displace;
    for(int i = 0; i < particles.size(); i++){
        if (&particles[i] == this) {
            continue;
        }
        
        // distance between me and particles[i]
        float dist = pow(particles[i].pos.x - pos.x, 2) + pow(particles[i].pos.y - pos.y, 2);
        dist = sqrt(dist);
        
        if (dist < 15.0) {
            displace  = displace - (particles[i].pos - pos);
        }
    }
    ofPoint separation_velocity;
    separation_velocity = displace/3;
    return separation_velocity;
}

void Particle::update(vector<Particle> &particles) {
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    ofPoint v1 = separation(particles);
    vel += v1;
    
    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
        pos.x -= vel.x; // Bounced back! think of this as an undo;
        vel.x *= -1.0;
    }
    
    if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
        pos.y -= vel.y; // Bounced back! think of this as an undo;
        vel.y *= -1.0;
    }
    
}

void Particle::draw() {
//    ofCircle(pos, radius);
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    ofPushMatrix();
    ofTranslate( pos );
    
    float rotAmt = atan2( vel.y, vel.x );
    ofRotate( ofRadToDeg(rotAmt) + 180 );
    ofSetColor(255,0,100);
//    ofDrawRectangle( 0,0, 15, 20);
    
    fish.draw(0,0,40,15);
    
    ofPopMatrix();
}