#include "menu_board.h"

void MenuBoard::drawMenu() {
    this->display->clearDisplay();
    this->display->setTextSize(this->fontSize);
    this->display->setTextColor(WHITE);
    this->drawVersion();
    this->display->setCursor(this->x0, this->y0);
    uint16_t varyingY = this->y0;
    for (int i = 0; i < 3; i++) {
      if (!this->items[i]->text) break;
      this->items[i]->draw(this->x0, varyingY);      
      varyingY += this->items[i]->height;
    }
    this->display->display();
}

void justPrintIt(Adafruit_SSD1306 *d) {
  Serial.println("Clicked!");
}

MenuBoard::MenuBoard(Adafruit_SSD1306 *display, uint16_t x0, uint16_t y0, uint16_t fontSize){
    this->display = display;
    this->x0 = x0;
    this->y0 = y0;
    this->fontSize = fontSize;
    for (int i = 0; i < 3; i++) {
      char buf[48];
      strcpy(buf, "Menu Item #");
      String text = String("Menu Item #");
      text.concat(i);
      this->items[i] = new MenuItem("Menu Item #", i == 0, display);
    }
}

MenuItem::MenuItem(char *text, bool isSelected, Adafruit_SSD1306 *display) {
    this->text = text;
    this->display = display;
    this->isSelected = isSelected;
    this->length = 6 * strlen(this->text);
}

void MenuItem::onClick() {
  this->display->clearDisplay();
  this->display->setTextColor(WHITE);
  this->display->setCursor(10, 10);
  this->display->println("AND MAGIC BALL SAYS...");
  this->display->display();
  delay(1000);
  this->display->clearDisplay();
  this->display->setCursor(20, 5);
  this->display->println("NO");
  this->display->display();
  delay(4000);
}

void MenuItem::draw(uint16_t x0, uint16_t y0) {
  if (!this->display) return;
  this->display->setCursor(x0, y0);
  if (this->isSelected) {
    this->display->setTextColor(BLACK, WHITE);
    this->display->print(" "); // small padding
  }
  this->display->println(this->text);
  this->display->setTextColor(WHITE);
}

int MenuBoard::getSelected() {
  for (int i = 0; i < 3; i++) {
    if (this->items[i]->isSelected) return i;
  }
}

void MenuBoard::setSelected(int i) {
  int previousSelected = this->getSelected();
  this->items[previousSelected]->isSelected = false;
  this->items[i]->isSelected = true;
}

void MenuBoard::clickMenuItem(int i) {
  this->items[i]->onClick();
}

void MenuBoard::drawVersion() {
  this->display->setCursor(95, 0);
  this->display->print(13.37);
}
