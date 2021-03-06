#pragma once

#include "ofMain.h"


class ofSnake {

public:

    ofSnake();
    ~ofSnake();

    float xSpeed;
    float ySpeed;
    
    int scl = 50;

    ofColor color;

    void updateSnake();
    void drawSnake();
    void pause();
    void newSnake();
    void setDir(int x, int y);
    string getDir();
    bool eat(ofVec2f foodPos);
    bool checkCollision(int x, int y);
    int getScore();
    bool killSnake();
    bool dead = false;
    int pScore;
    vector<ofVec2f> pPos;
    ofVec2f myPos { 0, 0 };
    vector<ofVec2f> snakePos;
    bool justAte = false;
    

	ofImage head;
    ofImage tail;

    
    
};
