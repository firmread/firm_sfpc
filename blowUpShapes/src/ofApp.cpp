#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
	ard.connect("/dev/tty.usbmodem1421", 57600);
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino	= false;
    
    
    countA = 0;
    countB = 0;
    countC = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    updateArduino();
    
    if(ard.getAnalog(0)> 500){
        countA+=5;
    } else if (countA>0)countA--;
    if(ard.getAnalog(1)> 500){
        countB+=5;
    } else if (countB>0)countB--;
    if(ard.getAnalog(2)> 500){
        countC+=5;
    } else if (countC>0)countC--;
    cout << ard.getAnalog(0) << endl;
}



//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
    
	// remove listener because we don't need it anymore
	ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    
	ard.sendAnalogPinReporting(0, ARD_ANALOG);
	ard.sendAnalogPinReporting(1, ARD_ANALOG);
	ard.sendAnalogPinReporting(2, ARD_ANALOG);
    
	bSetupArduino = true;
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    
	// update the arduino, get any data or messages.
	ard.update();
    
    
    
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(-90);
    
    ofSetColor(ofColor::orange,150);
    ofPushMatrix();
    ofScale(countC, countC);
    ofSetCircleResolution(4);
    ofCircle(0, 0, 1);
    ofPopMatrix();
    
    ofSetColor(ofColor::navy,150);
    ofPushMatrix();
    ofScale(countB, countB);
    ofSetCircleResolution(100);
    ofCircle(0, 0, 1);
    ofPopMatrix();
    
    ofSetColor(ofColor::lawnGreen,150);
    ofPushMatrix();
    ofScale(countA, countA);
    ofSetCircleResolution(3);
    ofCircle(0, 0, 1);
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key =='f') {
        ofToggleFullscreen();
    }
    
    if (key == 'a') {
        countA+=5;
    }
    if (key == 's') {
        countB+=5;
    }
    if (key == 'd') {
        countC+=5;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
	ard.sendDigital(13, ARD_HIGH);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
	ard.sendDigital(13, ARD_LOW);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
