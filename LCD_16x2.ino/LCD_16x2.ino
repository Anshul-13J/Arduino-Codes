#include <LiquidCrystal.h>

const int rs=12, en=11;
const int d4=2 , d5=3, d6=4, d7=5;
LiquidCrystal lcd(rs, en, d4, d5, d6,d7);

void setup()
{
  lcd.begin(16,2);
  
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Hello, World !");
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("Second line");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  char s[]="LCD 16x2";
  int i=0;
  for(i=0;i<sizeof(s)-1;i++)
  {
    
    lcd.print(s[i]);
    if(s[i]==' ')
      continue;
    delay(1000);
  }
  delay(2000);
}
