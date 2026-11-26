#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include "config.h"

Adafruit_ST7789 tft(&SPI, PIN_TFT_CS, PIN_TFT_DC, PIN_TFT_RESET);

//pour chaque couleur on inverse (par exemple noir est normalement 0x0000, on le remplace par 0xFFFF-0x0000 = 0xFFFF)
//on fait ça parce que sur l'écran les couleurs étaient inversées
/*
#define BLACK    0xFFFF
#define BLUE     0xFFE0
#define RED      0x07FF
#define GREEN    0xF81F
#define CYAN     0xF800
#define MAGENTA  0x07E0
#define YELLOW   0x001F 
#define WHITE    0x0000
*/
//deuxième solution : on inverse l'affichage avec tft.invertDisplay(false); dans le setup()
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

void setup() {
    SPI.begin(PIN_TFT_SCK, -1, PIN_TFT_MOSI, PIN_TFT_CS);  // pas de MISO
    tft.init(240, 320, SPI_MODE3);
    tft.invertDisplay(false);
    tft.setRotation(2);                                     // portrait
    tft.fillScreen(BLACK);

    tft.setTextSize(4);
    tft.setTextColor(WHITE);
    tft.setCursor(72, 40);
    tft.print("PONG");

    tft.drawRect(20, 120, 200, 60, WHITE);   // rectangle
    tft.fillCircle(120, 250, 20, YELLOW);    // disque
}

void loop() {}