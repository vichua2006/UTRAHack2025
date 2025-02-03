int addr = 0;
byte value = 100;


void writeIntIntoEEPROM(unsigned int number)
{ 
  byte byte1 = number >> 8;
  byte byte2 = number & 0xFF;
  EEPROM.write(COMPENSATION_ADDRESS, byte1);
  EEPROM.write(COMPENSATION_ADDRESS + 1, byte2);
}

int readIntFromEEPROM()
{
  byte byte1 = EEPROM.read(COMPENSATION_ADDRESS);
  byte byte2 = EEPROM.read(COMPENSATION_ADDRESS + 1);
  return (byte1 << 8) + byte2;
}

void save(){
  writeIntIntoEEPROM((old + millis()/1000));
}

int get(){
  int time = readIntFromEEPROM();
  return time;
}

void compensate(){
  float turn_scalar = (get()/600.0)*(2.0/3.0);
  tunableQuarterPiTime *= (1+turn_scalar);
  Serial.println(tunableQuarterPiTime);
}

void timeSave(){
  if ((millis() - time) >= 1000) {
    time = millis();
    save();
      compensate();
    }
}