int mem_date = 0;
int mem_month = 1;
int mem_year = 2;
int mem_hours = 3;
int mem_min = 4;

void eeprom_save(){
  int mod_year = (parameters[2] - 2000);
     EEPROM.update(mem_date,  parameters[0] );
      EEPROM.update(mem_month,  parameters[1] );
       EEPROM.update(mem_year,  mod_year);
        EEPROM.update(mem_hours,  parameters[3] );
         EEPROM.update(mem_min,  parameters[4] );
         
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("SAVING DATA");
  delay(2000);
  
}
