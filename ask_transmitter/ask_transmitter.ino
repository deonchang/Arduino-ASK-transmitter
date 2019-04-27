const int TX_PIN = 13;          // transmitter pin
const int TX_VCC = 12;          // transmitter VCC pin
const int PREAMB = 24;          // preamble length
const int BITS = 197;           // length of data
const int BIT_DURATION = 370;   // microseconds
const int PREAMB_DELAY = 3300;  // microseconds
const int REPEAT_DELAY = 1550;  // microseconds

int preamble[PREAMB] = {};
int data[BITS] = {};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TX_PIN, OUTPUT);
  pinMode(TX_VCC, OUTPUT);
  digitalWrite(TX_PIN, LOW);
  digitalWrite(TX_VCC, HIGH);
  digitalWrite(LED_BUILTIN, LOW);
}

void transmitPreamble() {
  for (int bit = 0; bit < PREAMB; bit++) {
    // Turn the transmitter on for one bit duration if the bit is a 1
    if (preamble[bit] == 1) {
      digitalWrite(TX_PIN, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else {
      // Bit is zero and therefore don't transmit anything for one bit duration
      digitalWrite(TX_PIN, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    // Transmit for one bit duration
    delayMicroseconds(BIT_DURATION);
  }
  // Turn off transmitter when we're finished
  digitalWrite(TX_PIN, LOW);
}

void transmitSeq() {
  for (int bit = 0; bit < BITS; bit++) {
    if (data[bit] == 1) {
      digitalWrite(TX_PIN, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
    } 
    else {
      digitalWrite(TX_PIN, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    delayMicroseconds(BIT_DURATION);
  }
  digitalWrite(TX_PIN, LOW);
}


void loop() {
  transmitPreamble();
  delayMicroseconds(PREAMB_DELAY);
  transmitSeq();
  delayMicroseconds(REPEAT_DELAY);
}
