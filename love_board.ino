#include <Adafruit_SSD1306.h>
#include <splash.h>
#include "menu_board.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define RED      0xF800
#define VERSION "13.37"

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
const uint16_t startX = 15;
const uint16_t startY = 15;
const uint16_t fontSize = 1;
MenuBoard menu(&display, startX, startY, fontSize);
int downButton = 0;
void setup() {
  randomSeed(analogRead(0));
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  display.clearDisplay();
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(A0, INPUT);
  Serial.println("TEst in setup.");
  menu.drawMenu();
}
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50; 
void loop() {
  delay(100);
  menu.drawMenu();
  downButton = digitalRead(10); // DOWN
  int idx = menu.getSelected();
  // read the state of the switch into a local variable:
  int upButton = digitalRead(9);
  if (upButton && idx > 0) {
    idx = idx - 1;
    menu.setSelected(idx);
  }
  if (downButton && idx < 2) {
    idx = idx + 1;
    menu.setSelected(idx);
  }
  if (digitalRead(8)) {  
    int i = menu.getSelected();
    Serial.println("CLICK CLICKED!" + i);
    menu.clickMenuItem(i);
  }
//  if (pinSignal > 40 && pinSignal < 70) {
//    // selection.y0 = selection.y0 + 15;
//  } else if (pinSignal > 10 && pinSignal < 40) {
//    // selection.y0 = selection.y0 - 15;
//  }
}
