#include "ofSnake.h"



ofSnake::ofSnake() {

    xSpeed = 0;
    ySpeed = 0;

    color.setHex(0x23391C);
    snakePos = vector<ofVec2f>();
    pPos = vector<ofVec2f>();
    snakePos.push_back(ofVec2f(0,0));

	head.load("snakehead.png");
	head.resize(scl, scl);
    tail.load("snakehead.png");
    tail.resize(scl, scl);
   

}

ofSnake::~ofSnake() {
    
}

void ofSnake::updateSnake() {
    ofVec2f snakeFront = snakePos.front();
    snakeFront.x = snakeFront.x + xSpeed * scl;
    snakeFront.y = snakeFront.y + ySpeed * scl;


    //snakeFront.x = ofClamp(snakeFront.x, -1, ofGetWidth() - scl);
    //snakeFront.y = ofClamp(snakeFront.y, scl+1, ofGetHeight() - scl);

	if (snakeFront.x > ofGetWidth() - scl) {
		snakeFront.x = 0;
	}else if (snakeFront.x < 0) {
		snakeFront.x = ofGetWidth();
	}else if (snakeFront.y > ofGetHeight()-scl) {
		snakeFront.y = 0;
	}else if (snakeFront.y < 0) {
		snakeFront.y = ofGetHeight();
	}

    snakePos.insert(snakePos.begin(), snakeFront);
    
    if(justAte){
        std::cout << snakePos.size() << std::endl;
        justAte = false;
    } else{
        snakePos.pop_back();
    }

   // if(snakeFront.x > ofGetWidth() ||snakeFront.x < 0 ||snakeFront.y > ofGetHeight() ||snakeFront.y <= 0 ){
    for(int i = 1; i < snakePos.size(); i++){
        std::cout << " snakeFront: "<< snakeFront << " snakePos: "<< snakePos[i]<< std::endl;
        if( snakePos.size() > 4 && snakeFront.x == snakePos[i].x && snakeFront.y == snakePos[i].y){
            snakePos.clear();
            dead = true;
        }
    }
    
 

}


void ofSnake::drawSnake() {

    ofSetColor(color);
	head.draw(snakePos[0].x, snakePos[0].y);
    //tail.draw(snakePos[snakePos.size()].x, snakePos[snakePos.size()].y);

    for(int i = 1; i < snakePos.size(); i++){

        ofDrawRectRounded(snakePos[i].x, snakePos[i].y, scl, scl, 10);
    }
}
bool ofSnake::killSnake() {
    pScore = (snakePos.size()-1)*10;
    if(dead){
        pPos.push_back(snakePos[0]);
            return true;
        } else{
            return false;
    }

    
}
void ofSnake::newSnake(){
    dead = false;
  
    snakePos.push_back(pPos[0]);
}

//doesn't work yet
bool ofSnake::checkCollision(int x, int y){
    for(int i = 0 ; i < snakePos.size(); i++){
        if(x == snakePos[i].x && y == snakePos[i].y ){
            return true;
    } else{
        return false;
    }
    }

}


void ofSnake::setDir(int x, int y) {
    xSpeed = x;
    ySpeed = y;
}

string ofSnake::getDir() {

    if( xSpeed == 1 && ySpeed == 0){
        return "right";
    } else if( xSpeed == -1 && ySpeed == 0){
        return "left";
    }else if( xSpeed == 0 && ySpeed == -1){
        return "up";
    }else if( xSpeed == 0 && ySpeed == 1){
        return "down";
    } else
        return "null";
}

int ofSnake::getScore(){
        return pScore;
   
}

bool ofSnake::eat(ofVec2f foodPos) {

    if (snakePos[0].distance(foodPos) < scl) {
        justAte = true;
        
        std::cout << " eat !" << std::endl;
       

        return true;
    }

    return false;

}
