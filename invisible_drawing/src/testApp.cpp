#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    // ofSetBackgroundAuto(false);
    ofSetFrameRate(30);
    ofSetColor(255);
}

//--------------------------------------------------------------
void testApp::update(){
    
    //    for (int i = 0; i < pts.size(); i++){
    //        pts[i].x += ofRandom(-1,1);
    //        pts[i].y += ofRandom(-1,1);
    // }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofNoFill();
    
    
    //ofBeginShape();
    //   myLine.curveTo(pts);
    //    myLine.draw();
    
    //for (int i = 0; i < pts.size(); i++){
    //  myLine.addVertex(pts[i].x, pts[i].y);
    // if ((mouse_xpos != last_mouse_xpos) && (mouse_ypos != last_mouse_ypos))
    //
    // {
    //    if (mouseRelease == true)
    //
    //    {
    //        mouse_xpos = mouseX;
    //        mouse_ypos = mouseY;
    //        mouseRelease = false;
    //    }
    
    myLine.draw();
    for (int i =0; i< olderLines.size(); i++)
    {
        olderLines[i].draw();
        //  olderLines[i].close();
    
        
    }
    if ( olderLines.size() > 0)
    {
        cout << " start of first data"<< endl;
        for ( int j = 0; j < olderLines[0].getVertices().size(); j++)
    cout<< olderLines[0].getVertices()[j]<< endl;
    
    }
    // ofEndShape();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key ==  57)
    {
        ofBackground(0);
    }
    if (key == 56)
    {
        ofBackground(255);
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    myLine.addVertex(x, y);
    
    // pts.push_back(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    
    
    olderLines.push_back(myLine);
    myLine.clear();
    
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