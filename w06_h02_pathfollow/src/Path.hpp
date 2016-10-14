//
//  Path.hpp
//  w06_h02_pathfollow
//
//  Created by Kris Li on 10/12/16.
//
//

#pragma once
#include "ofMain.h"

class Path {
public:
    Path();
    
    void init();
    void update();
    void addPoint(float x, float y);
    void draw();
    
    float radius;
    ofPoint begin, end;
    
//    vector<ofPoint> points;
//    ofPath path;
    
    
private:
    
};

//class Path {
//    
//    A Path is now an ArrayList of points (PVector objects).
//    ArrayList<PVector> points;
//    float radius;
//    
//    Path() {
//        radius = 20;
//        points = new ArrayList<PVector>();
//    }
//    
//    This function allows us to add points to the path.
//    void addPoint(float x, float y) {   .
//        PVector point = new PVector(x,y);
//        points.add(point);
//    }
//    
//    Display the path as a series of points.
//    void display() {
//        stroke(0);
//        noFill();
//        beginShape();
//        for (PVector v : points) {
//            vertex(v.x,v.y);
//        }
//        endShape();
//    }
//}