# How-to-Connect-Arduino-to-ADISRA-SCADA-Software-
This example shows how to connect ADISRA software to an Arduino using the Modbus serial protocol. No extra hardware is required, as we use the Modbus library on the Arduino. The same approach can be used to connect Arduino with other SCADA software.
The folowing examples cover three cases: sending data, receiving data, and sending/receiving data.

Note: The only difference between the [03] folder and [02] is that, in [03], the Arduino code uses millis() instead of delay(). This allows the blinking action to remain visible and responsive in the ADISRA graphics.
