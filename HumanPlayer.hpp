//
//  HumanPlayer.hpp
//  Othello
//
//  Created by 薩田和弘 on 2017/02/23.
//  Copyright © 2017年 Kazuhiro S. All rights reserved.
//

#ifndef HumanPlayer_hpp
#define HumanPlayer_hpp

#include "Player.hpp"

class HumanPlayer : public Player{
public:
  virtual std::tuple<int, int> putStone();
};

#endif /* HumanPlayer_hpp */
