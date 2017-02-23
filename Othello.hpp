//
//  Othello.hpp
//  Othello
//
//  Created by 薩田和弘 on 2017/02/23.
//  Copyright © 2017年 Kazuhiro S. All rights reserved.
//

#ifndef Othello_hpp
#define Othello_hpp

#include "Player.hpp"

class Othello{
public:
  void start(Player *player1, Player *player2);
  static Othello *getInstance();
private:
  static Othello *instance;
  Player *player1, *player2;
  
  Othello();
  void mainLoop();
};

#endif /* Othello_hpp */
