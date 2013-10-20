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
    
       
        ofImage finalImage;
        ofImage image1;
        ofImage image2;
    
        bool first_time = true;
 
        struct pixels_place
        {ofColor col;
         int    pos;
        };
    
        pixels_place pixels_obj;
        vector< pixels_place > pixels1;
        vector< pixels_place > pixels2;

    
    
    
    
		
};
