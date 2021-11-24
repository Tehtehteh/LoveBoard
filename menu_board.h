#pragma once
#include <Adafruit_SSD1306.h>
#include "magic_ball.h"
#define VERSION "13.37"
const int MAX_MENU_ITEMS = 3;

class MenuItem {
  public:
    uint16_t x0;
    uint16_t y0;
    uint16_t length;
    uint16_t height = 12;
    char *text;
    const uint16_t color = WHITE;
    bool isSelected;
    void draw(uint16_t x0, uint16_t y0);
    void onClick();
    MenuItem(char *text, bool isSelected, Adafruit_SSD1306 *display);
  private:
    Adafruit_SSD1306 *display;
};

class MenuBoard {  
  private:
    Adafruit_SSD1306 *display;
    uint16_t fontSize;
  public: 
    uint16_t x0;
    uint16_t y0;
    void drawMenu();
    MenuItem *items[MAX_MENU_ITEMS];
    MenuBoard(Adafruit_SSD1306 *display, uint16_t x0, uint16_t y0, uint16_t fontSize);
    void drawVersion();
    void clickMenuItem(int i);
    int getSelected();
    void setSelected(int);
};
