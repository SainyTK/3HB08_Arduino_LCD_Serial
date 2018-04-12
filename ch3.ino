/* Read a text received on serial arduino port and display on LCD*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ss=00;
int mm=00;
int hh=00;

int seconds;

void setup() 
{ 
  Serial.begin(9600); 
  lcd.begin(16, 2);
  // prints title with ending line break 
  lcd.setCursor(0,0);    //col, row
  lcd.print("HH:MM:SS");
} 

void loop() 
{
    if(seconds==(60*60*24))
    seconds = 0;
  seconds = millis()*10;
  
  lcd.setCursor(0,1);    //col, row
  hh = seconds/3600%24;
  if(hh<10)
    lcd.print(0);
  lcd.print(hh);
  
  lcd.setCursor(2,1);    //col, row
  lcd.print(':');

  mm = seconds/60%60;
  lcd.setCursor(3,1);    //col, row
  if(mm<10)
    lcd.print(0);
  lcd.print(mm);
  
  lcd.setCursor(5,1);    //col, row
  lcd.print(':');
  
  ss = seconds%60;
  lcd.setCursor(6,1);    //col, row
  if(ss<10)
    lcd.print(0);
  lcd.print(ss);
  
}
