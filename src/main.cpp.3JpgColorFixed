#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPIFFS.h>
#include <TJpg_Decoder.h>

TFT_eSPI tft = TFT_eSPI();

bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap) {
  if (y >= tft.height() || x >= tft.width()) return false;

  tft.startWrite();
  tft.setAddrWindow(x, y, w, h);
  tft.pushColors(bitmap, w * h, false);  // ← IMPORTANT
  tft.endWrite();

  return true;
}

void setup() {
  Serial.begin(115200);

  tft.init();
  tft.setRotation(1);
  tft.invertDisplay(false);
  tft.fillScreen(TFT_BLACK);

  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);

  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS failed");
    while (1);
  }

  TJpgDec.setCallback(tft_output);
  TJpgDec.setSwapBytes(true);   // ← IMPORTANT

  Serial.println("Drawing...");
  TJpgDec.drawFsJpg(0, 0, "/colorwordstest.jpg");
}

void loop() {}