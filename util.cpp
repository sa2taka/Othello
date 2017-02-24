#include "util.hpp"
#include <random>

namespace util{
  int createRandomNum(int minimum, int maximize){
    std::random_device rnd; //  乱数生成器の作成
    std::mt19937 mt(rnd()); //  メルセンヌ・ツイスタ
    std::uniform_int_distribution<> rand(minimum, maximize); //  範囲指定
    return rand(mt);
  }
}
