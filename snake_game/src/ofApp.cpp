#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(8);
    ofBackground(164,199,32);

    
    headFont.load("MechanismoRegular.ttf", 52);
    middleFont.load("MechanismoRegular.ttf", 22);
    smallFont.load("MechanismoRegular.ttf", 18);
    text = "Snake Game";
    btnTxt = "start";
    pauseTxt = "pause";
    gameOverTxt = "Game Over";
    againBtnTxt = "start again";
    
    startBtn.set(ofGetWidth()/2-100, ofGetHeight()/2, 200, 50);
    againBtn.set(ofGetWidth()/2-100, ofGetHeight()/2+headFont.stringHeight(text)*3, 200, 50);

 

    
}

//--------------------------------------------------------------
void ofApp::update(){
	
    if(!pause){
        mySnake.updateSnake();
    }

	if (mySnake.eat(myFood.myPos)) {
		myFood.pickLocation();
		
        if(foodColorIndex==0){
            myFood.color = ofColor(0x528CDE);
        }else if (foodColorIndex == 1){
            myFood.color = ofColor(0xDE3A26);
        }else if (foodColorIndex == 2){
            myFood.color = ofColor(0x912C20);
        } else if(foodColorIndex > 2) {
            foodColorIndex = 0;
        }
        foodColorIndex++;

	}
  

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(!gameover){
    score = ofToString(mySnake.getScore());
    }
    if(mySnake.killSnake()){
        gameover = true;
    } 
    
    if(startBtnClicked){
        screen = 2;
    } else if(againBtnClicked){
        screen = 2;
        gameover = false;
        mySnake.newSnake();
        againBtnClicked = false;
    } else  if(pause){
        screen = 3;
    } if(gameover){
        screen = 4;
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
            ofSetHexColor(0x23391C);
            //ofDrawRectangle(5,55,ofGetWidth()-5, ofGetHeight()-55);
            ofFill();
            break;
        case 2:
            mySnake.drawSnake();
            myFood.drawFood();
            smallFont.drawString("score: " + score, 20,ofGetHeight()-25 );
            break;


    }
    if(screen == 3){
        ofSetHexColor(0x23391C);
        headFont.drawString(pauseTxt, ofGetWidth()/2-headFont.stringWidth(pauseTxt)/2,ofGetHeight()/2-headFont.stringHeight(pauseTxt)/2);
        
    } else if(screen == 4){
        ofSetHexColor(0x23391C);
            headFont.drawString(gameOverTxt, ofGetWidth()/2 - headFont.stringWidth(gameOverTxt) / 2 , ofGetHeight() / 2 - headFont.stringHeight(gameOverTxt) / 2);
        string scoreTxt ="your score: " + score;
        middleFont.drawString(scoreTxt, ofGetWidth()/2 - middleFont.stringWidth(scoreTxt)/2, ofGetHeight()/2  + middleFont.stringHeight(scoreTxt)/2 + headFont.stringHeight(gameOverTxt));
        if(ofGetMouseX() < againBtn.x + againBtn.width && ofGetMouseX() > againBtn.x - againBtn.width && ofGetMouseY() < againBtn.y + againBtn.height && ofGetMouseY() > againBtn.y - againBtn.height){
            ofSetHexColor(0x23391C);
        }else{
            ofSetHexColor(0x232A18);
        }
        
        ofDrawRectangle(againBtn);
        ofSetHexColor(0xFFFFFF);
        middleFont.drawString(againBtnTxt, againBtn.x+middleFont.stringHeight(againBtnTxt)/2, againBtn.y +middleFont.stringHeight(againBtnTxt)*1.1);
            
    }
    

}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	switch (key) {

	case OF_KEY_LEFT: // left

            if(mySnake.getDir() != "right" ){
                mySnake.setDir(-1, 0);
                mySnake.head.rotate90(0 - rotation);
                rotation = 0;
            }
		break;
	case OF_KEY_RIGHT: // right
            if(mySnake.getDir() != "left" ){
                mySnake.setDir(1, 0);
                mySnake.head.rotate90(2 - rotation);
                rotation = 2;
            }
		break;
	case OF_KEY_UP: // up
            if(mySnake.getDir() != "down" ){
                mySnake.setDir(0, -1);
                mySnake.head.rotate90(1 - rotation);
                rotation = 1;
            }

	case OF_KEY_DOWN: // down

            if(mySnake.getDir() != "up" ){
                mySnake.setDir(0, 1);
                mySnake.head.rotate90(3 - rotation);
                rotation = 3;
            }

		
	

		break;
  
	}

        if(  key == OF_KEY_SPACE){
            if(!pause && screen == 2){
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
    againBtnClicked = againBtn.inside(x,y);
    std::cout << "screen: " << screen  << std::endl;

}



