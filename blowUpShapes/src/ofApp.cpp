#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    countA = 50;
    countB = 50;
    countC = 50;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(-90);
    
    ofSetColor(ofColor::navy,70);
    ofPushMatrix();
    ofScale(countA, countA);
    ofSetCircleResolution(3);
    ofCircle(0, 0, 1);
    ofPopMatrix();
    
    ofSetColor(ofColor::lawnGreen,70);
    ofPushMatrix();
    ofScale(countB, countB);
    ofSetCircleResolution(100);
    ofCircle(0, 0, 1);
    ofPopMatrix();
    
    ofSetColor(ofColor::fireBrick,70);
    ofPushMatrix();
    ofScale(countC, countC);
    ofSetCircleResolution(4);
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
