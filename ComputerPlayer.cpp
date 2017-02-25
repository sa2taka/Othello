#include "ComputerPlayer.hpp"
#include "Othello.hpp"
#include "util.hpp"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

std::tuple<int, int> ComputerPlayer::putStone(){
  auto *othelloInstance = Othello::getInstance();
  std::tuple<int, int> res;

  if(othelloInstance->countEmptyArea(othelloInstance->othello) > 0){
    res = decideByNormalWay();
  }
  else{
    decideBySearchWay();
  }

  return res;
}

void ComputerPlayer::copyOthelloArray(int copiedArray[8][8], int copyArray[8][8]){
  int x, y;
  for(y = 0;y < 8;y++){
    for(x = 0;x < 8;x++){
      copyArray[y][x] = copiedArray[y][x];
    }
  }
}


std::tuple<int, int> ComputerPlayer::decideByNormalWay(){
  int i;
  int minimumSize = 0;
  std::vector<int> minimumPuttableLocations;
  int othello[8][8];

  auto *othelloInstance = Othello::getInstance();
  int nowColor = othelloInstance->nowColor;
  int anotherColor = othelloInstance->nowColor == 1 ? 2 : 1;
  copyOthelloArray(othelloInstance->othello, othello);

  auto puttablePoint = othelloInstance->getPuttable(othello, nowColor);

  //  置ける場所の一つ目
  othelloInstance->turnOverStone(std::get<0>(puttablePoint[0]), std::get<1>(puttablePoint[0]), othello, nowColor);
  minimumPuttableLocations.push_back(0);
  minimumSize = othelloInstance->getPuttable(othello, anotherColor).size();

  //  以降おける場所全てに石を置いて相手が置ける場所を最も少なくするように行う
  for(i = 1;i < puttablePoint.size();i++){
    copyOthelloArray(othelloInstance->othello, othello);
    othelloInstance->turnOverStone(std::get<0>(puttablePoint[i]), std::get<1>(puttablePoint[i]), othello, nowColor);
    auto temp = othelloInstance->getPuttable(othello, anotherColor);

    if(temp.size() < minimumSize){
      minimumPuttableLocations.clear();
      minimumPuttableLocations.push_back(i);
      minimumSize = temp.size();
    }
    else if(temp.size() == minimumSize){
      minimumPuttableLocations.push_back(i);
    }
  }

  int returnRef = util::createRandomNum(0, minimumPuttableLocations.size() - 1);

  return puttablePoint[minimumPuttableLocations[returnRef]];
}

std::tuple<int, int> ComputerPlayer::decideBySearchWay(){
  auto *othelloInstance = Othello::getInstance();
  int othello[8][8];
  int nowColor = othelloInstance->nowColor;
  copyOthelloArray(othelloInstance->othello, othello);

  auto puttablePoints = othelloInstance->getPuttable(othello, nowColor);
  double maxmizePercent = 0;
  int maxmizePercentLocation = 0;

  for(int i = 0;i < puttablePoints.size();i++){
    double percent = getWinPercent(puttablePoints[i], othello, nowColor);
    if(percent > maxmizePercent){
      maxmizePercent = percent;
      maxmizePercentLocation = i;
    }
  }

  return puttablePoints[maxmizePercentLocation];
}

double ComputerPlayer::getWinPercent(std::tuple<int, int> puttablePoint,
                                int othello[8][8],
                                int nowColor){
  auto *othelloInstance = Othello::getInstance();
  int tempOthello[8][8];
  copyOthelloArray(othello, tempOthello);
  int anotherColor = nowColor == 1 ? 2 : 1;
  double totalPercent = 0;
  bool gameFinishFlag = false;

  othelloInstance->turnOverStone(std::get<0>(puttablePoint),
                                  std::get<1>(puttablePoint),
                                  tempOthello,
                                  nowColor);

  // 変更後における場所を取得
  auto puttablePoints = othelloInstance->getPuttable(tempOthello, anotherColor);
  if(puttablePoints.size() == 0){
    puttablePoints = othelloInstance->getPuttable(tempOthello, nowColor);
    if(puttablePoints.size() == 0){
      gameFinishFlag = true;
    }
  }
  if(othelloInstance->countEmptyArea(tempOthello) == 0 || gameFinishFlag){
    int return1, return2;
    if(othelloInstance->searchWinner(&return1, &return2) == othelloInstance->nowColor){
      return 1;
    }
    else{
      return 0;
    }
  }
  gameFinishFlag = false;

  for(int i = 0;i < puttablePoints.size();i++){
    totalPercent += getWinPercent(puttablePoints[i], tempOthello, anotherColor);
  }

  return totalPercent / puttablePoints.size();
}
