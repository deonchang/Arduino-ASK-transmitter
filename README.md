# Arduino ASK transmitter
Create an ASK transmitter using an Arduino and an external ASK RF module.

# Wiring up the hardware
For this sketch, I used [this](https://www.banggood.com/433Mhz-RF-Transmitter-With-Receiver-Kit-For-Arduino-ARM-MCU-Wireless-p-74102.html) 433 MHz ASK transmitter. We are interested in the DATA, VCC, and GND pin. Connect the DATA pin to an analogue or digital pin on the Arduino board and set the `TX_PIN` constant accordingly. I also used one of the pins (set in the constant `TX_VCC`) on the Arduino to provide power to the RF module.

# Sending the code
 I highly recommend using [URH](https://github.com/jopohl/urh) to find out what 'bits' are sent by your ASK device (e.g. remote control) and related timing measurements.

 1. Identiy the preamble and data bits in URH and copy them over to the `preamble` and `data` variables in the sketch. Count the number of bits for both and update the array lengths in the constants `PREAMB` and `BITS`. 
 2. Set the duration of each bit (in microsends) in the constant `BIT_DURATION`. 
 3. Set the delay (in microseconds) between the end of the last preamble bit to the beginning of the first data bit in the constant `PREAMB_DELAY`. 
 4. Similarly, the constant `REPEAT_DELAY` is how long your device waits (in microseconds) before repeating transmission (e.g. when the button on the remote is held down).
5. Connect everything up and power up the Arduino.