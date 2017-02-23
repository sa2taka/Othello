//
//  Othello.cpp
//  Othello
//
//  Created by 薩田和弘 on 2017/02/23.
//  Copyright © 2017年 Kazuhiro S. All rights reserved.
//

#include "Othello.hpp"
#include <stdio.h>

Othello *Othello::instance = new Othello();
Othello::Othello(){}

Othello *Othello::getInstance(){
  return instance;
}

void Othello::start(Player *player1, Player *player2){
  this->player1 = player1;
  this->player2 = player2;
  mainLoop();
}

void Othello::mainLoop(){
  printf("%d, %d\n", std::get<0>(player1->putStone()), std::get<1>(player1->putStone()));
}
