#ifndef Othello_hpp
#define Othello_hpp

#include "Player.hpp"
#include <vector>

class Othello{
public:
  static Othello *getInstance();
  int othello[8][8];
  int nowColor = 1;

  void start(Player *player1, Player *player2);
  std::vector<std::tuple<int, int>> getPuttable(int othello[8][8], int nowColor);
  int countEmptyArea(int othello[8][8]);
  void turnOverStone(int x, int y, int othello[8][8], int nowColor);
  int searchWinner(int *return1, int *return2);
private:
  static Othello *instance;
  Player *player1, *player2;

  bool beforePlayerPassFlag;

  Othello();
  void init();
  void mainLoop();
  void printOthello();
  bool isPuttable(int othello[8][8], int x, int y, int nowColor);
  bool isPuttableLine(int othello[8][8], int x, int y, int nowColor, int wayX, int wayY);
  void penetratePuttable(std::vector<std::tuple<int, int>> puttable);
  void depenetratePuttable();
};

#endif /* Othello_hpp */
