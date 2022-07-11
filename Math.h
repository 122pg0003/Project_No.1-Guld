#pragma once

class Vector2 {
public:
  // x成分,y成分
  float x, y;
  // コンストラクタ
  Vector2(float inX = 0, float inY = 0)
    :x{ inX }
    , y{ inY } {
  }
};