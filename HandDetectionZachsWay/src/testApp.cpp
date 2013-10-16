#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    gui = new ofxUICanvas(600,500,320,120);		//ofxUICanvas(float x, float y, float width, float height)
//	gui->addWidgetDown(new ofxUILabel("OFXUI TUTORIAL", OFX_UI_FONT_LARGE));
    gui->addWidgetDown(new ofxUISlider(304,16,0,300,0.0,"NEAR THRESHOLD"));
    gui->addWidgetDown(new ofxUISlider(304,16,0,300,0.0,"FAR THRESHOLD"));

  //  float w, float h, float _min, float _max, float _value, string _name)
    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    gui->loadSettings("GUI/guiSettings.xml");
 //   gui->addWidgetDown(new ofxUIToggle(32, 32, false, "FULLSCREEN"));
    
    
    
    
    
    ofSetLogLevel(OF_LOG_VERBOSE);
	
	// enable depth->video image calibration
	kinect.setRegistration(true);
    
	kinect.init();
	//kinect.init(true); // shows infrared instead of RGB video image
	//kinect.init(false, false); // disable video image (faster fps)
	
	kinect.open();		// opens first available kinect
	//kinect.open(1);	// open a kinect by id, starting with 0 (sorted by serial # lexicographically))
	//kinect.open("A00362A08602047A");	// open a kinect using it's unique serial #
	
	// print the intrinsic IR sensor values
	if(kinect.isConnected()) {
		ofLogNotice() << "sensor-emitter dist: " << kinect.getSensorEmitterDistance() << "cm";
		ofLogNotice() << "sensor-camera dist:  " << kinect.getSensorCameraDistance() << "cm";
		ofLogNotice() << "zero plane pixel size: " << kinect.getZeroPlanePixelSize() << "mm";
		ofLogNotice() << "zero plane dist: " << kinect.getZeroPlaneDistance() << "mm";
	}
	
    
	
	colorImg.allocate(kinect.width, kinect.height);
	grayImage.allocate(kinect.width, kinect.height);
	grayThreshNear.allocate(kinect.width, kinect.height);
	grayThreshFar.allocate(kinect.width, kinect.height);
	
	//nearThreshold = 230;
   // cout << nearThreshold << endl;
	//farThreshold = 70;
	bThreshWithOpenCV = true;
	
	ofSetFrameRate(60);
	
	// zero the tilt on startup
	angle = 0;
	kinect.setCameraTiltAngle(angle);
	
	// start from the front
	

}

//--------------------------------------------------------------
void testApp::update(){
    
    ofBackground(100, 100, 100);
	
	kinect.update();
	
	// there is a new frame and we are connected
	if(kinect.isFrameNew()) {
		
		// load grayscale depth image from the kinect source
		grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
		
		// we do two thresholds - one for the far plane and one for the near plane
		// we then do a cvAnd to get the pixels which are a union of the two thresholds
		if(bThreshWithOpenCV) {
			grayThreshNear = grayImage;
			grayThreshFar = grayImage;
			grayThreshNear.threshold(nearThreshold, true);
			grayThreshFar.threshold(farThreshold);
			cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
		} else {
			
			// or we do it ourselves - show people how they can work with the pixels
			unsigned char * pix = grayImage.getPixels();
			
			int numPixels = grayImage.getWidth() * grayImage.getHeight();
			for(int i = 0; i < numPixels; i++) {
				if(pix[i] < nearThreshold && pix[i] > farThreshold) {
					pix[i] = 255;
				} else {
					pix[i] = 0;
				}
			}
		}
		
		// update the cv images
		grayImage.flagImageChanged();
		
		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		contourFinder.findContours(grayImage, 10, (kinect.width*kinect.height)/2, 20, false);
    
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 255, 255);
	
    // draw from the live kinect
  //  kinect.drawDepth(10, 10, 400, 300);
  //  kinect.draw(420, 10, 400, 300);
    
    grayImage.draw(0, 0, 400, 300);
   contourFinder.draw(0, 0, 400, 300);
    
    for (int i = 0; i< contourFinder.blobs.size(); i++)
    {cout << contourFinder.blobs[i].centroid << endl;
        ofSetColor(255, 0, 0);
        ofCircle(contourFinder.blobs[i].centroid.x , contourFinder.blobs[i].centroid.y , 2);
        ofSetColor(255, 255, 255);
    }

	
	
	// draw instructions
	ofSetColor(255, 255, 255);
    
     
	    
	


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::exit()
{
	gui->saveSettings("GUI/guiSettings.xml");
    delete gui;
    
    
    kinect.setCameraTiltAngle(0); // zero the tilt on exit
	kinect.close();
	

}

void testApp::guiEvent(ofxUIEventArgs &e)
{
	if(e.widget->getName() == "FAR THRESHOLD")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        //ofBackground(slider->getScaledValue());
       farThreshold = slider->getScaledValue();
       // cout<< farThreshold<< endl;
    }
    else if(e.widget->getName() == "NEAR THRESHOLD")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        //ofBackground(slider->getScaledValue());
        nearThreshold = slider->getScaledValue();
        //cout<< farThreshold<< endl;
    }


    
}
