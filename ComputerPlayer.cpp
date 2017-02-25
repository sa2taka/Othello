#include "ComputerPlayer.hpp"
#include "Othello.hpp"
#include "util.hpp"
#include <iostream>
#include <stdio.h>
#include <unistd.h>

std::tuple<int, int> ComputerPlayer::putStone(){
  auto *othelloInstance = Othello::getInstance();
  std::tuple<int, int> res;

  if(othelloInstance->countEmptyArea() > 0){
    res = decideByNormalWay();
  }
  else{
    int othello[8][8];
    int nowColor = othelloInstance->nowColor;
    copyOthelloArray(othelloInstance->othello, othello);
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

std::tuple<int, int> ComputerPlayer::decideBySearchWay(int othello[8][8], int nowColor){
  int i, j;
  auto *othelloInstance = Othello::getInstance();
  int anotherColor = nowColor == 1 ? 2 : 1;
  auto puttablePoint = othelloInstance->getPuttable(othello, nowColor);
  int tempOthello[8][8];

  for(i = 0;i < 8;i++){
    for(j = 0;j < 8;j++){
      tempOthello[i][j] = othello[i][j];
    }
  }

  //  再帰的に呼び出して、最もかつ確率が高い手を選ぶ
  for(i = 0;i < puttablePoint.size();i++){
    othelloInstance->turnOverStone(std::get<0>(puttablePoint[i]), std::get<1>(puttablePoint[i]), othello, nowColor);
  }
}
