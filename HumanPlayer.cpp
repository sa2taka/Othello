#include "HumanPlayer.hpp"
#include <iostream>
#include <stdio.h>

std::tuple<int, int> HumanPlayer::putStone(){
  int x, y;
  printf("Xvalue_Yvalue(ex.'4 5')\n");
  std::cin >> x >> y;
  x--;
  y--;
  return std::make_tuple(x, y);
}
