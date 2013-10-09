#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
    
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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //  vector < ofPoint > pts;
    
    ofPolyline myLine;
    vector < ofPolyline > olderLines;
    int mouse_xpos;
    int mouse_ypos;
    bool mouseRelease = false;
    int last_mouse_xpos ;
    int last_mouse_ypos ;
    
    
    
};
