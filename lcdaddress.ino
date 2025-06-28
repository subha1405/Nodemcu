#include <Wire.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);  // Only needed for native USB boards, but safe to leave here

  // Set up I2C pins for NodeMCU
  Wire.begin(D2, D1);  // SDA = D2 (GPIO4), SCL = D1 (GPIO5)

  Serial.println("\nI2C Scanner");
  byte count = 0;

  for (byte i = 8; i < 120; i++) {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found device at address 0x");
      if (i < 16) Serial.print("0");
      Serial.print(i, HEX);
      Serial.print(" (");
      Serial.print(i, DEC);
      Serial.println(")");
      count++;
      delay(5);
    }
  }

  if (count == 0) {
    Serial.println("No I2C devices found.");
  } else {
    Serial.print("Total devices found: ");
    Serial.println(count);
  }
}

void loop() {
  // No need to repeat the scan
}
