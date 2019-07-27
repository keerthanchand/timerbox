void printScreen() {


  
  lcd.clear();
  lcd.print(screens[currentScreen][0]);
  lcd.setCursor(0, 1);
  lcd.print("      ");
  lcd.print(parameters[currentScreen]);
  lcd.print(" ");
  delay(40);

 
    
  
}
