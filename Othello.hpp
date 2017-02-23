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
  int othello[8][8];

  Othello();
  void mainLoop();
  void printOthello();
};

#endif /* Othello_hpp */
