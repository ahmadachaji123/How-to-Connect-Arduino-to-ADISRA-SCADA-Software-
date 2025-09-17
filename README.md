# How-to-Connect-Arduino-to-ADISRA-SCADA-Software-
This example shows how to connect ADISRA software to an Arduino using the Modbus serial protocol. No extra hardware is required, as we use the Modbus library on the Arduino. The same approach can be used to connect Arduino with other SCADA software.
The folowing examples cover three cases: sending data, receiving data, and sending/receiving data.

Note: The only difference between [03] folder and [02] is that we are using millis in the arduino code instead of delay to let the blinking action be visible on the graphics in ADISRA.

