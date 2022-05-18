#include "ofSnake.h"



ofSnake::ofSnake() {

    xSpeed = 0;
    ySpeed = 0;

    color.set(255);
    snakePos = vector<ofVec2f>();
    snakePos.push_back(ofVec2f(0,0));

}

ofSnake::~ofSnake() {
    
}

void ofSnake::updateSnake() {
 
    if(justAte){
        snakePos.push_back(snakePos[0]);
        std::cout << snakePos.size() << std::endl;
        justAte = false;
    }
    for(int i = 0; i < snakePos.size(); i++){
    snakePos[i].x = snakePos[i].x + xSpeed * scl;
    snakePos[i].y = snakePos[i].y + ySpeed * scl;

    //min-max range maped to canvas
    snakePos[i].x = ofClamp(snakePos[i].x, 0, ofGetWidth() - scl);
    snakePos[i].y = ofClamp(snakePos[i].y, 0, ofGetHeight() - scl);
    }
    

}


void ofSnake::drawSnake() {

    ofSetColor(color);
    
    for(int i = 0; i < snakePos.size(); i++){
        ofDrawRectangle(snakePos[i].x, snakePos[i].y, scl, scl);
    }

    
}


void ofSnake::setDir(int x, int y) {
    xSpeed = x;
    ySpeed = y;
}



bool ofSnake::eat(ofVec2f foodPos) {

    if (snakePos[0].distance(foodPos) < scl) {
        justAte = true;
        
        std::cout << " eat !" << std::endl;
       

        return true;
    }

    return false;

}
