#include "HumanPlayer.hpp"
#include "ComputerPlayer.hpp"
#include "Othello.hpp"
#include <iostream>
#include <unistd.h>

int main(int argc, const char * argv[]) {
  auto *player1 = new ComputerPlayer();
  auto *player2 = new ComputerPlayer();
  Othello *othello = Othello::getInstance();

  while(true){
    othello->start(player1, player2);
    usleep(1000000);
  }
  return 0;
}
