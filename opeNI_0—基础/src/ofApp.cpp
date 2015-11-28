#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  
    myKinect.setup();
    myKinect.addDepthGenerator();
    myKinect.addImageGenerator();
    myKinect.addUserGenerator();
    myKinect.start();
    myKinect.setMaxNumUsers(6);
    pos.set(-1000, -1000);
}

//--------------------------------------------------------------
void ofApp::update(){

    myKinect.update();
    for (int i=0; i<myKinect.getNumTrackedUsers(); i++){
        ofxOpenNIUser & user = myKinect.getTrackedUser(i);
        ofxOpenNIJoint head = user.getJoint(JOINT_HEAD);
        pos = head.getProjectivePosition();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    ofSetColor(255);
    myKinect.drawDebug();
 
    ofSetColor(200, 0, 120);
    ofCircle(pos.x, pos.y, 30);
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