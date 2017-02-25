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
    decideBySearchWay(othello, nowColor);
  }

  return res;
}

void copyOthelloArray(int copiedArray[8][8], int copyArray[8][8]){
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

  auto puttablePoint = othelloInstance->getPuttable(othello, nowColor);
  int maxmizePercent = 0;

  for(int i = 0;i < puttablePoint.size();i++){
    double percent = searchWay(puttablePoint[i], othello, nowColor);
  }
}

double ComputerPlayer::searchWay(std::tuple<int, int> puttablePoints,
                                int ohtello[8][8],
                                int nowColor){
  auto *othelloInstance = Othello::getInstance();
  int tempOthello[8][8];
  copyOthelloArray(othello, tempOthello);
  int anotherColor = nowColor == 1 ? 2 : 1;
  double totalPercent 0;

  othelloInstance->turnOverStone(std::get<0>(puttablePoint[i]),
                                  std::get<1>(puttablePoint[i]),
                                  tempOthello,
                                  anotherColor);

  // 変更後における場所を取得
  auto puttablePoint = othelloInstance->getPuttable(othello, nowColor);

  if(ohtelloInstance->countEmptyArea()){

  }

  for(int i = 0;i < puttablePoint.size();i++){

  }
}
