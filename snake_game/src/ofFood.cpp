#include "ofFood.h"


ofFood::ofFood() {

    color.set(0x232A18);
    
    // set the first position of food randomly
    // otherwise food and snake have the same pos at (0,0) which leads to an error
    // in "snake's eat function > startcheck is increased w/o reason"
    pickLocation();
}

ofFood::~ofFood() {

}


void ofFood::pickLocation() {

    int cols = floor(ofGetWidth() / scl);
    int rows = floor(ofGetHeight() / scl);

    myPos.x = floor(ofRandom(cols))*scl;
    myPos.y = floor(ofRandom(rows))*scl;

    cout << "PICKED " << myPos.x << endl;
}


void ofFood::drawFood() {
    ofSetColor(color);
    ofDrawRectRounded(myPos.x,myPos.y, scl, scl, 10);
}

