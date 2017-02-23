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

int Othello::getNowColor(){
  return nowColor;
}

std::vector<std::tuple<int, int>> Othello::getPuttable(int Othello[8][8], int nowColor){
  int i, j;
  std::vector<std::tuple<int, int>> res;
  for(i = 0;i < 8;i++){
    for(j = 0;j < 8;j++){
      if(isPuttable(othello, j, i, nowColor)){
        res.push_back(std::make_tuple(j, i));
      }
    }
  }
  return res;
}

void Othello::mainLoop(){
  //while(true){
  system("clear");
  auto puttablePoint = getPuttable(othello, nowColor);
  penetratePuttable(puttablePoint);
  printOthello();
  depenetratePuttable();
  //}
}

void Othello::printOthello(){
  /*
  int i, j;
  for(i = 0;i < 8;i++){
    for(j = 0;j < 8;j++){
      switch(othello[i][j]){
        case 0: printf(" "); break;
        case 1: printf("O"); break;
        case 2: printf("X"); break;
        case 3: printf("*"); break;
      }
    }
    printf("\n");
  }
  */
  int i, j;
  char showOthello[8][8];
  for(i = 0;i < 8;i++){
    for(j = 0;j < 8;j++){
      switch(othello[i][j]){
        case 0: showOthello[i][j] = ' '; break;
        case 1: showOthello[i][j] = 'O'; break;
        case 2: showOthello[i][j] = 'X'; break;
        case 3: showOthello[i][j] = '*'; break;
      }
    }
  }
	printf("      ");
	for(j = 0;j < 8;j++)
		printf(" %d  ", j + 1);
	putchar('\n');
	printf("     ");
	for(j = 0;j < 8;j++)
		printf("----");
	puts("-");
	for(i = 0;i < 8;i++)
	{
		printf("  %2d |",i + 1);
		for(j = 0;j < 8;j++)
			printf(" %c |",showOthello[i][j]);
		putchar('\n');
		printf("     ");
		for(j = 0;j < 8;j++)
			printf("----");
		puts("-");
	}
}

bool Othello::isPuttable(int othello[8][8], int x, int y, int nowColor){
  int i;
  int wayX = 0, wayY = 0;
  bool res = false;
  for(i = 0;i < 8;i++){
    switch(i){
      case 0: wayX = 0; wayY = -1; break;
      case 1: wayX = 1; wayY = -1; break;
      case 2: wayX = 1; wayY = 0;break;
      case 3: wayX = 1; wayY = 1; break;
      case 4: wayX = 0; wayY = 1; break;
      case 5: wayX = -1; wayY = 1; break;
      case 6: wayX = -1; wayY = 0;break;
      case 7: wayX = -1; wayY = -1; break;
    }
    res = isPuttableLine(othello, x, y, nowColor, wayX, wayY);
    if(res){
      break;
    }
  }
  return res;
}

bool Othello::isPuttableLine(int othello[8][8], int x, int y, int nowColor, int wayX, int wayY){
  int tempX = x, tempY = y;
  int anotherColor = nowColor == 1 ? 2 : 1;
  bool differentFlag = false;
  bool res = false;

  while(true){
    if(tempX + wayX < 0 || tempX + wayX > 7){
      break;
    }
    tempX += wayX;
    if(tempY + wayY < 0 || tempY + wayY > 7){
      break;
    }
    tempY += wayY;
    if(differentFlag == false && othello[tempY][tempX] != anotherColor){
      break;
    }
    if(differentFlag == true && othello[tempY][tempX] == nowColor){
      res = true;
      break;
    }
    if(othello[tempY][tempX] == anotherColor){
      differentFlag = true;
    }
  }
  return res;
}

void Othello::penetratePuttable(std::vector<std::tuple<int, int> > puttable){
  int i;
  for(i = 0;i < puttable.size();i++){
    othello[std::get<1>(puttable[i])][std::get<0>(puttable[i])] = 3;
  }
}

void Othello::depenetratePuttable(){
  int i, j;
  for(i = 0;i < 8;i++){
    for(j = 0;j < 8;j++){
      if(othello[i][j] == 3){
        othello[i][j] = 0;
      }
    }
  }
}
