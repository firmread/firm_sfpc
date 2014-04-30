#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    grabber.initGrabber(640,480);
    grabberAsGray.allocate(640, 480, OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < 8; i++){
        bitPlanes[i].allocate(640, 480, OF_IMAGE_GRAYSCALE);
    };
    
    ofEnableAlphaBlending();
    
	autoShader.load("shaders/livecoding");
    autoShader.setMillisBetweenFileCheck(100);
    
    int selectedBit = 5;
    
    
    
    
    
    //audio
    int bufferSize = 256;
	
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
    
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
    
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    

}

//--------------------------------------------------------------
void testApp::update(){

    grabber.update();
    
    if (grabber.isFrameNew()){
        
        unsigned char * colorPix = grabber.getPixels();
        unsigned char * grayPix = grabberAsGray.getPixels();
        
        for (int i = 0; i < 640*480; i++){
            grayPix[i] = colorPix[i*3];
            
            for (int j = 0; j < 8; j++){
                bitPlanes[j].getPixels()[i] = (grayPix[i] >> (7-j)) & 0x01 ? 255 : 0;
                
            }
        }
        
    }
    
    grabberAsGray.update();
    for (int i = 0; i < 8; i++){
        bitPlanes[i].update();
    }
    
    
    
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    autoShader.begin();
    autoShader.setUniform1f("time", ofGetElapsedTimef());
    //every pixel you get access to this
//    autoShader.setUniformTexture("texBit", bitPlanes[selectedBit].getTextureReference(), 0);
    autoShader.setUniform2f("windowSize", ofGetWidth(), ofGetHeight());
    autoShader.setUniform2f("mousePos", mouseX, mouseY);
    autoShader.setUniform1f("vol", scaledVol);
    ofRect(0,0, ofGetWidth(), ofGetHeight() );
    autoShader.end();
    
    
    ofSetWindowTitle("FPS: " + ofToString(ofGetFrameRate()));
    
    bitPlanes[selectedBit].draw(0,0, ofGetWidth(), ofGetWidth()*.75);
    
    
//    grabberAsGray.draw(0,0);
//    
//    
//    for (int i = 0; i < 8; i++){
//        bitPlanes[i].draw((i%4)*ofGetWidth()/4, 240 + (i/4) * ofGetWidth()/4 * (240.0/320.0),ofGetWidth()/4, ofGetWidth()/4 * (240.0/320.0));
//    }
    
    
    
}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
	
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;
    
	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;
        
		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	//this is how we get the mean of rms :)
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :)
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == 'f') {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    selectedBit++;
    selectedBit%=8;
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