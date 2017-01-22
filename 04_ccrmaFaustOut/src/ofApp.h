#pragma once

#include "ofMain.h"
#include "faust/FaustReverb.h" // the Faust module

class ofApp : public ofBaseApp{

public:

    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
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
    
    void audioOut(float * input, int bufferSize, int nChannels);
    
    
    ofSoundStream soundStream;

    float 	pan;
    int		sampleRate, nInputChans;
    bool 	bNoise;
    float 	volume;

    vector <float> lAudio;
    vector <float> rAudio;
    
    //------------------- for the simple sine wave synthesis
    float 	targetFrequency;
    float 	phase;
    float 	phaseAdder;
    float 	phaseAdderTarget;

    //------------------- for Faust reverb stuff!
    float **audioBuffer; // The 2d audio buffer that Faust wants to work with
    
    FaustReverb reverb; // the Faust module (Reverb.h)
    MapUI reverbControl; // used to easily control the Faust module (Reverb.h)
    
    ofMutex myMutex;
    
};

//========================================================================
int main( ){
    
    ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp( new ofApp());
    
}
