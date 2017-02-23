#include "HumanPlayer.hpp"
#include "Othello.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
  HumanPlayer *player1 = new HumanPlayer();
  HumanPlayer *player2 = new HumanPlayer();
  Othello *othello = Othello::getInstance();

  othello->start(player1, player2);
  return 0;
}
