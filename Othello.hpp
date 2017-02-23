#ifndef Othello_hpp
#define Othello_hpp

#include "Player.hpp"
#include <vector>

class Othello{
public:
  static Othello *getInstance();

  void start(Player *player1, Player *player2);
  int getNowColor();
  std::vector<std::tuple<int, int>> getPuttable(int othello[8][8], int nowColor);
  int countEmptyArea();
private:
  static Othello *instance;
  Player *player1, *player2;
  int othello[8][8];
  int nowColor = 1;
  bool beforePlayerPassFlag;

  Othello();
  void mainLoop();
  void printOthello();
  bool isPuttable(int othello[8][8], int x, int y, int nowColor);
  bool isPuttableLine(int othello[8][8], int x, int y, int nowColor, int wayX, int wayY);
  void penetratePuttable(std::vector<std::tuple<int, int>> puttable);
  void depenetratePuttable();
  void turnOverStone(int x, int y);
  int searchWinner();
};

#endif /* Othello_hpp */
