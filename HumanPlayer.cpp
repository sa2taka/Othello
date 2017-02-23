//
//  HumanPlayer.cpp
//  Othello
//
//  Created by 薩田和弘 on 2017/02/23.
//  Copyright © 2017年 Kazuhiro S. All rights reserved.
//

#include "HumanPlayer.hpp"
#include <iostream>

std::tuple<int, int> HumanPlayer::putStone(){
  int x, y;
  std::cin >> x >> y;
  x--;
  y--;
  return std::make_tuple(x, y);
}
