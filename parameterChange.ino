void parameterChange(int key) {


  
  if (key == 0 && currentScreen == 0 && parameters[currentScreen] >= 31) {
    parameters[currentScreen] = 1;
    }

else if (key == 0 && currentScreen == 1 && parameters[currentScreen] >= 12) {
    parameters[currentScreen] = 1;
    }

else if (key == 0 && currentScreen == 2 && parameters[currentScreen] >= 2025) {
    parameters[currentScreen] = 2019;
    }
else if (key == 0 && currentScreen == 3 && parameters[currentScreen] >= 23) {
    parameters[currentScreen] = 0;
    }

else if (key == 0 && currentScreen == 4 && parameters[currentScreen] >= 59) {
    parameters[currentScreen] = 0;
}
else if (key == 0 && currentScreen == 5){
  eeprom_save();
 
  }
  else if (key == 0 && currentScreen == 6){
  datesave();
 
  }

  else if(key ==0) {
    parameters[currentScreen]++;
  } 
  
  // decrease 
  
if (key == 1 && currentScreen == 0 && parameters[currentScreen] <= 1) {
    parameters[currentScreen] = 31;
    }
    
else if (key == 1 && currentScreen == 1 && parameters[currentScreen] <= 1) {
    parameters[currentScreen] = 12;
    }


else if (key == 1 && currentScreen == 2 && parameters[currentScreen] <= 2019) {
    parameters[currentScreen] = 2025;
    }

    
else if (key == 1 && currentScreen == 3 && parameters[currentScreen] <= 0) {
    parameters[currentScreen] = 23;
    }

else if (key == 1 && currentScreen == 4 && parameters[currentScreen] <= 0) {
    parameters[currentScreen] = 59;
    }
else if(key == 1 && currentScreen ==5){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Cancelled");
  delay(2000);
    currentScreen = 5;
}
else if(key == 1 && currentScreen ==6){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Cancelled");
  delay(2000);
    currentScreen = 6;
}
    else if(key == 1){
     parameters[currentScreen]--;
  }
}
