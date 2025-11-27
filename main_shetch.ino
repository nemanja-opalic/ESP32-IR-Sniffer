#include <IRremote.h>

int RECV_PIN = 13;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();  // start receiver
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.print("Code: ");
        Serial.println(results.value, HEX);

        irrecv.resume();  // receive next value
    }
}
