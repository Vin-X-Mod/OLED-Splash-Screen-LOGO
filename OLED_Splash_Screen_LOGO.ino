/******************************************************************************
  Add a LOGO Splash Screen to your 128x64 OLED by Vin.X.Mod
  This will show Splash Screen of your LOGO for 5 seconds then BLANK screen.
  ... Then you can add whatever code you wish to LOOP in Void Loop.
  Press your Arduino's RESET BUTTON to see Splash Screen again.

  Online Image to C Array Converter at: https://lvgl.io/tools/imageconverter
  Adafruit 128x64 OLED Graphic Display: https://www.adafruit.com/product/326

  Tutorial and Example Sketches at:
  https://github.com/Vin-X-Mod/OLED-Splash-Screen-LOGO
******************************************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


static const unsigned char PROGMEM image_data_LOGOarray[] = { 
  // Add Splash Screen LOGO C-File Array here

};


void setup() {
  Serial.begin(9600);
   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
}
  
  delay(2000); // Pause for 2 seconds

  display.clearDisplay();  // Clear the buffer

// Displays LOGOarray on the screen
  display.drawBitmap(0, 0, image_data_LOGOarray, 128, 64, 1);
  display.display();

  delay(5000); // Keeps LOGOarray on OLED 5 seconds before Looping  
}


void loop() {
  display.clearDisplay();  // Clear the buffer
  display.display(); //  Clears LOGOarray Splash Screen
  // Add whatever you want to LOOP here
  
}
// End of OLED Splash Screen LOGO Sketch  
