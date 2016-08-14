void setup() {
  Serial.begin(38400);
}

void loop() {
  for(int i = 1; i < 4; i++){
    int value = analogRead(A1);
    byte one = byte(i << 4);
    one += byte(value >> 8) & 0x03;
    byte two = value & 0xFF;
      Serial.write(one);
      Serial.write(two);
      delay(3);
  }
}
