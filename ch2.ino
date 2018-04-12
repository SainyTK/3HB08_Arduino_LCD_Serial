#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define INLENGTH 16
#define INTERMINATOR 13
char inString[INLENGTH+1];
int inCount;
int incomingByte = 0;

void setup() 
{ 
  Serial.begin(9600); 
  lcd.begin(16, 2);
  // prints title with ending line break 
  Serial.println("Reads incoming serial data and display on LCD.");
  //pinMode(13, OUTPUT); 
  //digitalWrite(13, HIGH);   // set the LED on
  lcd.setCursor(0,0);    //col, row
  lcd.println("Ready to receive");
} 

void loop() 
{
  inCount = 0;
  do 
  {
    while (!Serial.available());             // wait for input
    inString[inCount] = Serial.read();       // get it
    Serial.print(inString[inCount]);
    
    if (inString[inCount] == INTERMINATOR) {
      inString[inCount] = 0;
      break;
    }
    ++inCount;
  } while(inCount < INLENGTH);
  
  lcd.clear();
  
  lcd.setCursor(0,0);    //col, row
  lcd.println("Ready to receive");
  lcd.setCursor(0,1);    //col, row
  
  lcd.print(inString);
  Serial.print("\nIn String : ");
  Serial.println(inString);
  
  inString[0] = 0;                     // null terminate the string

}
