#include "HumanPlayer.hpp"
#include <iostream>
#include <stdio.h>

std::tuple<int, int> HumanPlayer::putStone(){
  int x, y;
  std::cin >> x >> y;
  printf("%d, %d\n", x, y);
  x--;
  y--;
  return std::make_tuple(x, y);
}
