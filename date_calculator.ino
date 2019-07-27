




void dateconv () {

  int modout = (EEPROM.read(2) + 2000);
  unsigned long t1;
  unsigned long t2;
  unsigned long t3;
  unsigned long t4;




  DateTime now = rtc.now();
  DateTime future (modout, EEPROM.read(1), EEPROM.read(0), EEPROM.read(3) , EEPROM.read(4), 0);
  t1 = (future.unixtime() - now.unixtime());

  t2 = t1 / 3600;
  t3 = t1 % 60;
  t4 = (t1 / 60) % 60;
  if (now.unixtime() > future.unixtime()) {
    lcd.clear();
    lcd.write(2);

    lcd.write(2);

    lcd.write(2);

    lcd.write(2);

    lcd.print("SURPRISE");
    lcd.write(2);
    lcd.write(2);

    lcd.write(2);

    lcd.write(2);

    delay(40);
    myservo.write(end_pnt);

  }
  else {


    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" Time Remaining");
    lcd.setCursor(0, 1);
    lcd.print(t2);
    lcd.print(":");
    lcd.print(t4);
    lcd.print(":");
    lcd.print(t3);
    delay(40);
    myservo.write(start_pnt);

  }
  if (t1 <= 11 && t1 > 0) {
    digitalWrite(A0, HIGH);
    delay(500);
    digitalWrite(A0, LOW);
    delay(500);
  }
  else if (t1 == 0) {
    digitalWrite(A0, HIGH);
    delay(3000);
    digitalWrite(A0, LOW);

  }
}
