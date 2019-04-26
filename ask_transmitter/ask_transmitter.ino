const int TX_PIN = 2;          // transmitter pin
const int BITS = 220;          // number of sequence
const int BIT_DURATION = 370;  // microseconds

int bits[BITS] = {};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TX_PIN, OUTPUT); 
  digitalWrite(TX_PIN, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Transmitting...");
  for (int bit = 0; bit < BITS; bit++) {
    // Turn the transmitter on for one bit duration if the bit is a 1
    if (bits[bit] == 1) {
      digitalWrite(TX_PIN, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
      delayMicroseconds(BIT_DURATION);
      digitalWrite(TX_PIN, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    } 
    else {
      // Bit is zero and therefore don't transmit anything for one bit duration
      digitalWrite(TX_PIN, LOW);
      digitalWrite(LED_BUILTIN, LOW);
      delayMicroseconds(BIT_DURATION);
    }
  }
  Serial.println("Transmission completed!");
}
