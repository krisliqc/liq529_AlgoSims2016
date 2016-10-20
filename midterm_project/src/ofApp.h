#pragma once

#include "ofMain.h"
#include "Ripple.hpp"
#include "Drop.hpp"
#include "Boat.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    //ripple
    vector<Ripple> ripples;
    int num;
    ofxIntSlider rippleM;
    ofxFloatSlider wave;
    
    //drop
    vector<Drop> drops;
    int numX;
    int numY;
    ofxFloatSlider damping;
    ofxIntSlider area;
    
    //boat
    Boat boat1;
    Boat boat2;
    float r;
    ofPoint dest1;
    ofPoint dest2;
    ofxFloatSlider repulsion;
    int step;
    
    //cam
    ofEasyCam cam;
    ofImage sky;
    ofLight sun;
    
    ofxIntSlider x;
    ofxIntSlider y;
    ofxIntSlider z;
    ofxIntSlider xAngle;
    
    ofxPanel gui;
};
