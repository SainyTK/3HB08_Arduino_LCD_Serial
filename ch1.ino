// include the library code:
#include <LiquidCrystal.h>

// these constants won't change.  But you can change the size of
// your LCD using them:
const int numRows = 2;
const int numCols = 16;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(numCols,numRows);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tanakorn Masran");
  // loop from ASCII 'a' to ASCII 'z':

      for (int thisCol = 0; thisCol <= 9; thisCol++) {
        // set the cursor position:
        lcd.setCursor(thisCol,1);
        lcd.print(thisCol);
        delay(200);
      }
  
}






