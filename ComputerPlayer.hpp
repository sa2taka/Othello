#ifndef ComputerPlayer_hpp
#define ComputerPlayer_hpp

#include "Player.hpp"

class ComputerPlayer : public Player{
public:
  virtual std::tuple<int, int> putStone();
private:
  void copyOthello(int othello[8][8]);
  std::tuple<int, int> decideByNormalWay();
};

#endif /* Computer_hpp */
