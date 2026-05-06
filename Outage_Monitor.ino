#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2); //adress of lcd

const int gridPin = 2;   // The Slide Switch (Grid Simulator)
const int alertLed = 13; // Red LED for visual alert
int gridStatus = 0;
//array containing zones or locations of outage 
const char* locations[] = {"A01", "A02", "A03", "A04", "A05"};
int totalLocations = 5;

void setup() {
  pinMode(gridPin, INPUT);
  pinMode(alertLed, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  

  lcd.setCursor(0, 0);
  lcd.print("xyz SMART GRID");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM STARTING");
  delay(2000);
  lcd.clear();
}

void loop() {
  gridStatus = digitalRead(gridPin);

  if (gridStatus == HIGH) {
    // NORMAL OPERATION
    digitalWrite(alertLed, LOW);
    lcd.setCursor(0, 0);
    lcd.print("GRID STATUS:GOOD ");
    lcd.setCursor(0, 1);
    lcd.print("Vin: 230V NOM. ");
  } 
  else {
    digitalWrite(alertLed, HIGH);
  
  // Picking a random index from the list
  int randomIndex = random(0, totalLocations); 
  
  lcd.setCursor(0, 0);
  lcd.print("** OUTAGE!!  ** ");
  lcd.setCursor(0, 1);
  lcd.print("LOC: ");
  lcd.print(locations[randomIndex]); // Printing random place
  lcd.print("       "); // Extra spaces to clear long names
  
  delay(3000);
  digitalWrite(alertLed, LOW);
  delay(150);
  }
}
