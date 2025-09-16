
// NOTE!!!!!!!!! :the register number in this code (ex: 1) represent the register number here +1 in Adisra (ex: 2)

#include <ArduinoRS485.h>   // Required for ArduinoModbus
#include <ArduinoModbus.h>

uint16_t counter = 0;
uint8_t Number = 14 ; 
bool LED_status = 0 ; 

void setup() {

  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);


  // Start Modbus RTU slave on Serial, slave ID 1
  if (!ModbusRTUServer.begin(1, 9600)) {
    while (1);
  }

  // Configure 4 holding registers   || 0x00 is the first register  {0, 1, 2, 3, 4}
  ModbusRTUServer.configureHoldingRegisters(0x00, 5);

}


void loop() {

  ModbusRTUServer.poll();


// --- Send data to Adisra -----------------------------------------------------------------------------


  //Write to the register **0** in modbus the value of **counter**
  ModbusRTUServer.holdingRegisterWrite(0, counter); // 0 here represent 1 in Adisra 
  counter++;


  //Write to the register **1** in modbus the calue of **Number**
  ModbusRTUServer.holdingRegisterWrite(1, Number);  // 1 here represent 2 in Adisra 


// --- Receive data from Adisra ----------------------------------------------------------------------


  bool ledControl = ModbusRTUServer.holdingRegisterRead(2);  // Register 3 in Adisra
  if (ledControl == 1) {
    digitalWrite(LED_BUILTIN, HIGH);  // Turn ON LED
      ModbusRTUServer.holdingRegisterWrite(4, 1); //  sending the LED status as High 
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);                   // Turn OFF LED
        ModbusRTUServer.holdingRegisterWrite(4, 0); //  sending the LED status as LOW 
    }


  bool ledBlink = ModbusRTUServer.holdingRegisterRead(3);  // Register 4 in Adisra
  if (ledBlink == 1 && ledControl ==1 ) {
    digitalWrite(LED_BUILTIN, HIGH); 
      delay(250);
    digitalWrite(LED_BUILTIN, LOW);
      
  } 


  delay(150); 
}
