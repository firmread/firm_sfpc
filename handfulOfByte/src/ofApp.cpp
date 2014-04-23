#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    number = 0;
    font.loadFont("apr.otf", 32);
    
    int buttonSize = ofGetWidth()/8;
    for (int i =0 ; i<8; i++) {
        inputs[i].set(i*buttonSize, ofGetHeight()-buttonSize, buttonSize, buttonSize);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    font.drawString( ofToString(number), 50, 50);
    
    for (int i = 0; i < 8; i++){
        if ((number >> (7-i)) & 0x01){
            font.drawString(  "1" , 50 + i * 30, 100);
        }
        else {
            font.drawString(  "0" , 50 + i * 30, 100);
        }
        
    }
    
    ofPushStyle();
    ofSetColor(ofColor::cyan);
    ofSetLineWidth(3);
    
    for (int i = 0; i < 8; i++){
        
        if(!bInputs[i])ofNoFill();
        else ofFill();
        ofRect(inputs[i]);
    }
    ofPopStyle();
    
}



void ofApp::setBit(int var, int bit){
    
    var |= 1 << bit;
}

void ofApp::clearBit(int var, int bit){
    
    var &= ~(1 << bit);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'a'){
        number |= 1 << 7;
    }
    if (key == 's'){
        number |= 1 << 6;
    }
    if (key == 'd'){
        number |= 1 << 5;
    }
    if (key == 'f'){
        number |= 1 << 4;
    }
    if (key == 'j'){
        number |= 1 << 3;
    }
    if (key == 'k'){
        number |= 1 << 2;
    }
    if (key == 'l'){
        number |= 1 << 1;
    }
    if (key == ';'){
        number |= 1 << 0;
    }
    if (key == ' '){
//        number |= 1 << 8;
        number = 0;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == 'a'){
        number &= ~(1 << 7);
    }
    if (key == 's'){
        number &= ~(1 << 6);
    }
    if (key == 'd'){
        number &= ~(1 << 5);
    }
    if (key == 'f'){
        number &= ~(1 << 4);
    }
    if (key == 'j'){
        number &= ~(1 << 3);
    }
    if (key == 'k'){
        number &= ~(1 << 2);
    }
    if (key == 'l'){
        number &= ~(1 << 1);
    }
    if (key == ';'){
        number &= ~(1 << 0);
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for (int i = 0; i<8; i++) {
        if(inputs[i].inside(x, y)){
            bInputs[i] = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for (int i = 0; i<8; i++) {
        if (inputs[i].inside(x, y)) {
            bInputs[i] = false;
        }
    }
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
