void homescreen(){
  DateTime now = rtc.now();

  lcd.clear();
  lcd.setCursor(0,0);

  lcd.print("Date :");
  lcd.print(now.day());
    lcd.print('/');
    lcd.print(now.month());
    lcd.print('/');
    lcd.print(now.year());
        lcd.print("  ");
  lcd.setCursor(0,1);
  lcd.print("Time :");
     lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
    delay(50);
}
