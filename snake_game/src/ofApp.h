#pragma once

#include "ofMain.h"
#include "ofSnake.h"
#include "ofFood.h"



class ofApp : public ofBaseApp{

	public:
	
		void setup();
		void update();
		void draw();


		void keyPressed(int key);
    void mousePressed(int x, int y, int button);
		
    ofSnake mySnake{};
    ofFood myFood{};
    ofTrueTypeFont headFont;
    ofTrueTypeFont middleFont;
    ofTrueTypeFont smallFont;
    string text;
    string btnTxt;
    string againBtnTxt;
    string pauseTxt;
    string gameOverTxt;
    int screen = 1;
    const int OF_KEY_SPACE = 32;
    bool pause;
    bool gameover;
    bool startBtnClicked = false;
    bool againBtnClicked = false;
    string score = "0";
    ofRectangle startBtn;
    ofRectangle againBtn;
    
};
