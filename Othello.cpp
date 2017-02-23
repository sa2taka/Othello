#include "Othello.hpp"
#include <stdio.h>
#include <stdlib.h>

Othello *Othello::instance = new Othello();
Othello::Othello(){
  int i, j;
  for(i = 0;i < 8;i++){
    for(j = 0;j < 8;j++){
      othello[i][j] = 0;
    }
    printf("\n");
  }
  othello[3][3] = 1;
  othello[3][4] = 2;
  othello[4][3] = 2;
  othello[4][4] = 1;
}

Othello *Othello::getInstance(){
  return instance;
}

void Othello::start(Player *player1, Player *player2){
  this->player1 = player1;
  this->player2 = player2;
  mainLoop();
}

void Othello::mainLoop(){
  //while(true){
    system("clear");
    printOthello();
  //}
}

void Othello::printOthello(){
  int i, j;
  for(i = 0;i < 8;i++){
    for(j = 0;j < 8;j++){
      switch(othello[i][j]){
        case 0: printf(" "); break;
        case 1: printf("O"); break;
        case 2: printf("X"); break;
      }
    }
    printf("\n");
  }
}
