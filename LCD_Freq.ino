#include <LiquidCrystal.h>

// written By Fixed Until Broken on Youtube

const int pulsePin = 8; // Input signal connected to Pin 8 of Arduino
int pulseH; // Integer variable to capture High time of the incoming pulse
float pulseT; // Float variable to capture Total time of the incoming pulse
float frequency; // Calculated Frequency

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
lcd.begin(16, 2);
lcd.clear();
}

void loop()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Freq:");
pulseH = pulseIn(pulsePin, HIGH);
pulseT = pulseH * 2 ; // Time period of the pulse in microseconds
frequency = 1000000 / pulseT; // Frequency in Hertz (Hz)

if (frequency > 0 && frequency < 10000000){
  lcd.setCursor(0,1);
  lcd.print(frequency);
  lcd.print("Hz");
}
else{
  lcd.setCursor(0,1);
  lcd.print("out of range");
}

delay(500);

}
