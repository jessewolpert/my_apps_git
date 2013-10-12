#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
  //use these temp variables to allocate space to the vectors
   
    input_image_bw.loadImage("bw_jesse.jpg");
    input_image_bw.setImageType(OF_IMAGE_GRAYSCALE);
    input_image_cl.loadImage("color_jesse.jpg");
    input_image_cl.setImageType(OF_IMAGE_COLOR);

   
    //this sets up the images in the vector and the space for the array of char *'s
      //this allocates space for the final image and the window size
    finalImage.allocate(input_image_cl.width, input_image_cl.height, OF_IMAGE_COLOR);
    //ofSetWindowShape(myImages[0].width*2, myImages[0].height);
    ofSetWindowShape(input_image_cl.width, input_image_cl.height);
}

//--------------------------------------------------------------
void testApp::update(){
  unsigned char * newPixels = finalImage.getPixels();
  unsigned char * inputImagebwPixels = input_image_bw.getPixels();
  unsigned char * inputImageclPixels  = input_image_cl.getPixels();
//this bit of code is to do the reordering pixels of my face
    
    //start of sorting by grayscale image
//    if (first_time){
//        for (int j = 0; j <= 255; j++){
//             for (int i = 0; i < input_image_bw.width * input_image_bw.height ; i++){
//             int input_pixel = inputImagebwPixels[i];
//             if (input_pixel == j){
//                newPixels[3* pixel_count_new] = inputImageclPixels[ 3*i];
//                newPixels[(3* pixel_count_new) + 1] = inputImageclPixels[ (3* i) +1];
//                newPixels[(3* pixel_count_new) + 2] = inputImageclPixels[(3* i) +2];
//                pixel_count_new++;
//                                  }
//                                                                                     }
//        }
//        finalImage.update();
//        first_time = false;
//        }
//}
   // end of sorting by gray scale

            
            
        
        
        // start of sorting by color image hue
if (first_time){
    for (int j = 0; j <= 255; j++){
         for (int i = 0; i < input_image_cl.width * input_image_cl.height *3 ; i+=3){
                ofColor current_color(inputImageclPixels[i], inputImageclPixels[i+1], inputImageclPixels[i+2]);
                int input_pixel = current_color.getHue();
             
                      if (input_pixel == j)
                        {
                            newPixels[3* pixel_count_new] = inputImageclPixels[ i];
                                      newPixels[(3* pixel_count_new) + 1] = inputImageclPixels[i +1];
                                    newPixels[(3* pixel_count_new) + 2] = inputImageclPixels[i +2];
                                    pixel_count_new++;
                                       }
                      }
}
    finalImage.update();
    first_time = false;

}
}

// end of sorting by color image hue



//--------------------------------------------------------------
void testApp::draw(){
    
//myImages[0  ].draw(0,0);
  //  finalImage.draw(myImages[0].width, 0);
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