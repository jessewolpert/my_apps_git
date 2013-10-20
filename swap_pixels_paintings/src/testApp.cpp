#include "testApp.h"


bool ligSort(pixels_place a, pixels_place b)
{
    return a.col.getLightness() < b.col.getLightness();
}




//--------------------------------------------------------------
void testApp::setup(){
    
  //use these temp variables to allocate space to the vectors
   
  
    image1.loadImage("portrait1.jpg");
    image1.setImageType(OF_IMAGE_COLOR);
    image2.loadImage("portrait2.jpg");
    image2.setImageType(OF_IMAGE_COLOR);
    

   
    
    finalImage.allocate(image1.width, image1.height, OF_IMAGE_COLOR);
    ofSetWindowShape(image1.width, image1.height);
}

//--------------------------------------------------------------
void testApp::update(){
  unsigned char * newPixels = finalImage.getPixels();
  unsigned char * Image1Pixels  = image1.getPixels();
  unsigned char * Image2Pixels  = image2.getPixels();
    
    
    if (first_time == true){
//sort first image by lightness
        for (int i = 0; i < image1.width * image1.height *3 ; i+=3){
            
            ofColor current_color(Image1Pixels[i], Image1Pixels[i+1], Image1Pixels[i+2]);
          
            pixels_obj.col = current_color;
            pixels_obj.pos = i;
            pixels1.push_back(pixels_obj);
        }
        
        ofSort(pixels1, ligSort);
//sort second image by lightness
        for (int i = 0; i < image2.width * image2.height *3 ; i+=3){
            
            ofColor current_color(Image2Pixels[i], Image2Pixels[i+1], Image2Pixels[i+2]);
          
            pixels_obj.col = current_color;
            pixels_obj.pos = i;
            pixels2.push_back(pixels_obj);
            
            
        }
        
        ofSort(pixels2, ligSort);
    
//put colours from second image into first image
        for (int i = 0; i < pixels1.size(); i++){
              pixels1[i].col = pixels2[i].col;
          }
//sort first image by position (colours of image2 in position of image1)
        ofSort(pixels1, pixels_place.pos);
    
//write first image into final image
        for (int i = 0; i < pixels1.size(); i++){
            
                        
            newPixels[i*3] = pixels1[i].col.r;
            
            newPixels[i*3+1] = pixels1[i].col.g;
            
            newPixels[i*3+2] = pixels1[i].col.b;
            
            
            
        }
        
        finalImage.update();
        first_time = false;
    }

}


//--------------------------------------------------------------
void testApp::draw(){
    
    finalImage.draw(0, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
if (key == 's')
{ ofSaveFrame();}
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