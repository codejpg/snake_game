#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(8);
    ofBackground(164,199,32);
    startBtn.set(ofGetWidth()/2-100, ofGetHeight()/2, 200, 50);
    
    headFont.load("MechanismoRegular.ttf", 52);
    middleFont.load("MechanismoRegular.ttf", 22);
    smallFont.load("MechanismoRegular.ttf", 18);
    text = "Snake Game";
    btnTxt = "start";
    pauseTxt = "pause";
    gameOverTxt = "Game Over";

    
}

//--------------------------------------------------------------
void ofApp::update(){
	
    if(!pause){
        mySnake.updateSnake();
    }

	if (mySnake.eat(myFood.myPos)) {
		myFood.pickLocation();
	}
    if(mySnake.killSnake()){
        screen = 4;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(startBtnClicked){
        screen = 2;
    }
    switch (screen){
        case 1:
            ofBackground(164,199,32);
            ofSetHexColor(0x23391C);
            headFont.drawString(text, ofGetWidth()/2-headFont.stringWidth(text)/2,ofGetHeight()/2-headFont.stringHeight(text)/2);
            
            if(ofGetMouseX() > ofGetWidth()/2-100 && ofGetMouseX() < ofGetWidth()/2+100 && ofGetMouseY() > ofGetHeight()/2 && ofGetMouseY() < ofGetHeight()/2+50){
                ofSetHexColor(0x23391C);
            }else{
               
                ofSetHexColor(0x232A18);
            }
            
            ofDrawRectangle(startBtn);
            
            ofSetHexColor(0xFFFFFF);
     
            middleFont.drawString(btnTxt, ofGetWidth()/2 - middleFont.stringWidth(btnTxt)/2, ofGetHeight()/2 + middleFont.stringHeight(btnTxt)/2 + 25 );
          
            ofNoFill();
            ofSetLineWidth(5);
            ofSetHexColor(0x232A18);
            ofDrawRectangle(5,55,ofGetWidth()-5, ofGetHeight()-55);
            ofFill();
            break;
        case 2:
            mySnake.drawSnake();
            myFood.drawFood();
            smallFont.drawString(ofToString(mySnake.getScore()), 10,20 );
            break;
        case 3:
            headFont.drawString(pauseTxt, ofGetWidth()/2-headFont.stringWidth(text)/2-headFont.stringWidth(text)/2,ofGetHeight()/2-headFont.stringHeight(text)/2);
            
            break;
        case 4:
                headFont.drawString(gameOverTxt, ofGetWidth()/2-headFont.stringWidth(text)/2-headFont.stringWidth(text)/2,ofGetHeight()/2-headFont.stringHeight(text)/2);
                
                break;
    }

    

}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	switch (key) {

	case OF_KEY_LEFT: // left
		mySnake.setDir(-1, 0);
		break;
	case OF_KEY_RIGHT: // right
		mySnake.setDir(1, 0);
		break;
	case OF_KEY_UP: // up
		mySnake.setDir(0, -1);
		break;
	case OF_KEY_DOWN: // down
		mySnake.setDir(0, 1);
		break;
  
	}

        if(  key == OF_KEY_SPACE){
            if(!pause){
            pause = true;
            screen=3;
            } else {
            pause = false;
            screen=2;

        }
        }
}

void ofApp::mousePressed(int x, int y, int button){

    startBtnClicked = startBtn.inside(x,y);
    std::cout << "screen: " << screen  << std::endl;

}



