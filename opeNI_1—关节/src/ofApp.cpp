#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  
    myKinect.setup();
    myKinect.addImageGenerator();
    myKinect.addDepthGenerator();
    myKinect.setRegister(true);
    myKinect.setMirror(true);
    myKinect.addUserGenerator();
    myKinect.setMaxNumUsers(2);
    myKinect.start();
    
    pos.set(-1000, -1000);
    head_Sven.loadImage("sven.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    myKinect.update();

    for (int i=0; i<myKinect.getNumTrackedUsers(); i++) {
        ofxOpenNIUser & user = myKinect.getTrackedUser(i);
        ofxOpenNIJoint hand = user.getJoint(JOINT_RIGHT_HAND);
        if (hand.isFound()) {
            pos = hand.getProjectivePosition();
        }else{
            pos.set(-1000, -1000);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    ofSetColor(255, 255, 255);
    myKinect.drawDebug();
    
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    head_Sven.draw(-head_Sven.getWidth()/2,-head_Sven.getHeight()/2);
    ofPopMatrix();
    
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