#include "magic_ball.h"


char* MagicBall::ask() {
  char choices[5][20] = {
      "Ask later...",
      "Definately YES!",
      "Hell no!",
      "Maybe, I'm not sure.",
      "50/50"
    };
  return choices[1];
}

MagicBall::MagicBall() {}
