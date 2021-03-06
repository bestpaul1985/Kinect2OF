#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  
    myKinect.setup();
    myKinect.addImageGenerator();
    myKinect.addDepthGenerator();
    myKinect.setRegister(true);
    myKinect.setMirror(true);
    myKinect.addHandsGenerator();
    myKinect.addHandFocusGesture("Wave");
    ofAddListener(myKinect.handEvent,this,&ofApp::handEvent);
    myKinect.setMaxNumHands(4);
    myKinect.start();
    
    soundPlayer.loadSound("sound/rooster.mp3");
}

//--------------------------------------------------------------
void ofApp::update(){

    myKinect.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
   
    ofSetColor(255, 255, 255);
    myKinect.drawDebug();
    
}

//--------------------------------------------------------------
void ofApp::handEvent(ofxOpenNIHandEvent & event){
    
    if(event.handStatus == HAND_FOCUS_GESTURE_RECOGNIZED){
        soundPlayer.play();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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