#ifndef ComputerPlayer_hpp
#define ComputerPlayer_hpp

#include "Player.hpp"
#include <vector>

class ComputerPlayer : public Player{
public:
  virtual std::tuple<int, int> putStone();
private:
  void copyOthelloArray(int copiedArray[8][8], int copyArray[8][8]);
  std::tuple<int, int> decideByNormalWay();
  std::tuple<int, int> decideBySearchWay();
  double searchWay(std::tuple<int, int> puttablePoints, int ohtello[8][8], int nowColor);
};

#endif /* Computer_hpp */
