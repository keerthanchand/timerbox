void datesave(){
rtc.adjust(DateTime(parameters[2], parameters[1], parameters[0], parameters[3], parameters[4], 0));

lcd.setCursor(0,0);
lcd.clear();
lcd.print("Date & Time");
lcd.setCursor(0,1);
lcd.print("Updated");
delay(2000);
}
