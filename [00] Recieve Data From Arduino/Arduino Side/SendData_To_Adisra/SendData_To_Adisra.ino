
  // NOTE!!!!!!!!! :the register number in this code (ex: 1) represent the register number here +1 in Adisra (ex: 2)


#include <ArduinoRS485.h>   // Required for ArduinoModbus
#include <ArduinoModbus.h>


uint16_t counter = 0;
uint16_t Number = 14 ; 


void setup() {

  Serial.begin(9600);

  // Start Modbus RTU slave on Serial, slave ID 1
  if (!ModbusRTUServer.begin(1, 9600)) {
    while (1);
  }

  // Configure 2 holding registers   || 0x00 is the first register  {0, 1}
  ModbusRTUServer.configureHoldingRegisters(0x00, 2);

}

void loop() {

  ModbusRTUServer.poll();

  //Write to the register **0** in modbus the value of **counter**
  ModbusRTUServer.holdingRegisterWrite(0, counter); // 0 here represent 1 in Adisra 
  counter++;

  //Write to the register **1** in modbus the calue of **Number**
  ModbusRTUServer.holdingRegisterWrite(1, Number);  // 1 here represent 2 in Adisra 


  delay(1000);
  
}
