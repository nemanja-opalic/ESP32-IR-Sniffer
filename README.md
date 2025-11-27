# ESP32 IR Sniffer

This is a simple IR sniffer for ESP32 that reads codes from an IR remote and displays them in the Serial Monitor. This project is ideal for learning IR communication, automation projects, or tracking button presses.

---

## 📌 Features

- Works with ESP32 (tested on ESP32 S3 Waveshare Geek)
- Reads IR remote codes
- Displays HEX codes in the Serial Monitor
- Simple, stable, and perfect for demonstration or learning

---

## ⚙️ Required Materials

- ESP32 development board
- IR receiver module (e.g., KY-022)
- IR remote
- USB cable to connect ESP32 to PC

---

## 🛠 Installation

1. Install Arduino IDE: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
2. Install the ESP32 board support:
   - Preferences → Additional Board Manager URLs → add:  
     `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
   - Tools → Board → Boards Manager → ESP32 → Install
3. Install the IRremote library:
   - Sketch → Include Library → Manage Libraries → search for `IRremote` → Install
4. Connect ESP32 and IR receiver:
   - VCC → 3.3V
   - GND → GND
   - OUT → GPIO 13 (or change the pin in the code)

---

## 💻 Usage

1. Open Arduino IDE and upload `sketch_nov1a.ino`:

```cpp
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
