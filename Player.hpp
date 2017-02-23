#ifndef Player_h
#define Player_h

#include <tuple>

class Player{
public:
  virtual std::tuple<int, int> putStone() = 0;
};

#endif /* Player_h */
