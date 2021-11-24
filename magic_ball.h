#pragma once
#include <Adafruit_SSD1306.h>

class MagicBall {
  public:
    int MAX_POSSIBLE_CHOICES = 4;
    char choices[4][20] = {
      "Ask later...",
      "Definately YES!",
      "Hell no!",
      "Maybe, I'm not sure."
    };
    static char *ask();
    MagicBall();
};
