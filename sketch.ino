#include <ezButton.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire,-1);
ezButton button1(13);
ezButton button2(33);
ezButton button3(14);
ezButton button4(27);
ezButton button5(26);

int vote1=0, vote2=0, vote3=0, vote4=0;
int flag=0;

void setup() {
  Serial.begin(9600);
  button1.setDebounceTime(25);
  button2.setDebounceTime(25);
  button3.setDebounceTime(25);
  button4.setDebounceTime(25);
  button5.setDebounceTime(25);
  if(!oled.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println(F("Alocation Failed"));
    for(;;);
  };
  delay(2000);
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);

  oled.setCursor(2,5);
  oled.println("Start");
  oled.setCursor(2,21);
  oled.println("Voting...");
  oled.display();
  delay(2000);
}

void loop() {
  button1.loop();
  button2.loop();
  button3.loop();
  button4.loop();
  button5.loop();

  if(flag==0){
    oled.clearDisplay();
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.setCursor(2,0);
    oled.println("A - Green");
    oled.setCursor(2,16);
    oled.println("B - Yellow");
    oled.setCursor(2,32);
    oled.println("C - Red");
    oled.setCursor(2,48);
    oled.println("D - Blue");
    oled.display();
    flag=1;

  }
  delay(10);
}
