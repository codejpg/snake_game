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
    ofVec2f snakeFront = snakePos.front();
    snakeFront.x = snakeFront.x + xSpeed * scl;
    snakeFront.y = snakeFront.y + ySpeed * scl;

    snakeFront.x = ofClamp(snakeFront.x, 0, ofGetWidth() - scl);
    snakeFront.y = ofClamp(snakeFront.y, 0, ofGetHeight() - scl);
    
    snakePos.insert(snakePos.begin(), snakeFront);
    
    if(justAte){
        std::cout << snakePos.size() << std::endl;
        justAte = false;
    } else{
        snakePos.pop_back();
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
