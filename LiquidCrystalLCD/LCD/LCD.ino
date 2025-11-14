#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 2, 4, 5, 6,7);


void setup() {
  lcd.begin(16, 2);

}

void loop() {
  lcd.clear();
  delay(3000);
  lcd.print("Send");
  delay(3000);
  lcd.setCursor(0,1);
  lcd.print("Nude");
  delay(3000);

  lcd.clear();
}
