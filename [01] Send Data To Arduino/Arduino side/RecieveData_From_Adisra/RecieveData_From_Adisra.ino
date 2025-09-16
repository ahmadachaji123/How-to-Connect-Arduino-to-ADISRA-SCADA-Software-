
// NOTE!!!!!!!!! :the register number in this code (ex: 1) represent the register number here +1 in Adisra (ex: 2)


#include <ArduinoRS485.h>  // Required for ArduinoModbus
#include <ArduinoModbus.h>


void setup() {

  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);


  // Start Modbus RTU slave on Serial, slave ID 1
  if (!ModbusRTUServer.begin(1, 9600)) {
    while (1)
      ;
  }

  // Configure 3 holding registers   || 0x00 is the first register  {0, 1, 2, 3}
  ModbusRTUServer.configureHoldingRegisters(0x00, 4);
}

void loop() {

  ModbusRTUServer.poll();


  // --- Receive data from Adisra ---
  bool ledControl = ModbusRTUServer.holdingRegisterRead(2);  // Register 3 in Adisra

  if (ledControl == 1) digitalWrite(LED_BUILTIN, HIGH);  // Turn ON LED
  else digitalWrite(LED_BUILTIN, LOW);                   // Turn OFF LED


  bool ledBlink = ModbusRTUServer.holdingRegisterRead(3);  // Register 4 in Adisra

  if (ledBlink == 1 && ledControl ==1 ) {
    digitalWrite(LED_BUILTIN, HIGH);  
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
  } 


  delay(100);
}
