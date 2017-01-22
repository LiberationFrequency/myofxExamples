#pragma once

#include "ofMain.h"
#include "faust/FaustReverb.h" // the Faust module

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
				
		void audioIn(float * input, int bufferSize, int nChannels);
		void audioOut(float * output, int bufferSize, int nChannels);
	

		vector <float> left;
		vector <float> right;
		vector <float> volHistory;
		
		int 	bufferCounter;
		int 	drawCounter;

		
		float smoothedVol;
		float scaledVol;
		
		ofSoundStream soundStream;

    //------------------- for Faust reverb stuff!
    float **audioBuffer; // The 2d audio buffer that Faust wants to work with
    
    FaustReverb reverb; // the Faust module (Reverb.h)
    MapUI reverbControl; // used to easily control the Faust module (Reverb.h)

    ofMutex myMutex;

};
