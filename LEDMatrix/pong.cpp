#include "pong.h"

#include "control_LED.h"
#include "control_button.h"

bool stopGame;
int ballx;
int bally;
int ballDirectionx;
int ballDirectiony;
int player1;
int player2;

void startGame() {
  initializeGame();
  while (!stopGame) {
    moveBall();
    checkButtons();
    delay(100);
    checkButtons();
    delay(100);
    checkButtons();
    delay(100);
    checkButtons();
    delay(100);
    checkButtons();
    delay(100);
    checkButtons();
    delay(100);
    checkButtons();
    delay(100);
  }
  eraseAll();
}

void initializeGame() {
  stopGame = false;
  ballx = random(5, 6);
  bally = random(5, 6);
  player1 = 5;
  player2 = 5;
  ballDirectionx = random(-2, 2);
  if (ballDirectionx >= 0) {
    ballDirectionx ++;
  }
  ballDirectiony = random(-1, 1);
  if (ballDirectiony >= 0) {
    ballDirectiony ++;
  }
  oneLED(ballx, bally, 255, 255, 255);
  oneLED(0, player1, 255, 255, 255);
  oneLED(0, player1 + 1, 255, 255, 255);
  oneLED(11, player2, 255, 255, 255);
  oneLED(11, player2 + 1, 255, 255, 255);
}


void moveBall() {
  int ballxBefore = ballx;
  int ballyBefore = bally;
  ballx += ballDirectionx;
  if((bally + ballDirectiony == player1 || bally + ballDirectiony == player1 + 1 || bally == player1 || bally == player1 + 1) && ballx <= 1) {
    ballDirectionx = -1 * ballDirectionx;
  } 
  if((bally + ballDirectiony == player2 || bally + ballDirectiony == player2 + 1 || bally == player2 || bally == player2 + 1) && ballx >= 10) {
    ballDirectionx = -1 * ballDirectionx;
  } 
  if(ballx >= 11 || ballx <= 0) {
    stopGame = true;
  }
    if(12 > (bally + ballDirectiony) && (bally + ballDirectiony) > -1) {
      bally += ballDirectiony;
    } else {
      ballDirectiony = -1 * ballDirectiony;
    }
  oneLED(ballxBefore, ballyBefore, 0, 0, 0);
  oneLED(ballx, bally, 255, 255, 255);
}

void checkButtons() {
  if (isPressed(3) && player2 != 0) {
    player2 -= 1;
    oneLED(11, player2, 255, 255, 255);
    oneLED(11, player2 + 2, 0, 0, 0);
  }
  if (isPressed(4) && player2 != 10) {
    player2 += 1;
    oneLED(11, player2 - 1, 0, 0, 0);
    oneLED(11, player2 + 1, 255, 255, 255);
  }
  if (isPressed(5) && player1 != 0) {
    player1 -= 1;
    oneLED(0, player1, 255, 255, 255);
    oneLED(0, player1 + 2, 0, 0, 0);
  }
  if (isPressed(6) && player1 != 10) {
    player1 += 1;
    oneLED(0, player1 - 1, 0, 0, 0);
    oneLED(0, player1 + 1, 255, 255, 255);
  }
}
