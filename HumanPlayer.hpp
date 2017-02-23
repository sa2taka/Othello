#ifndef HumanPlayer_hpp
#define HumanPlayer_hpp

#include "Player.hpp"

class HumanPlayer : public Player{
public:
  virtual std::tuple<int, int> putStone();
};

#endif /* HumanPlayer_hpp */
