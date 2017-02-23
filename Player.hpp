//
//  Player.hpp
//  Othello
//
//  Created by 薩田和弘 on 2017/02/23.
//  Copyright © 2017年 Kazuhiro S. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <tuple>

class Player{
public:
  virtual std::tuple<int, int> putStone() = 0;
};

#endif /* Player_h */
