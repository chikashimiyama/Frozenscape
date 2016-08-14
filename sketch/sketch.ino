void setup() {
  analogReference(EXTERNAL);
  Serial.begin(38400);
  
}

void loop() {
  for(int i = 1; i < 4; i++){
    int value = analogRead(i);
    
    //data byte one   ID(1) 0 CH CH 0 B9 B8 B7 
    byte one = byte(i << 4) + 0x80; 
    one += byte(value >> 7) & 0x07; // high 3bit
    
    //data byte two   ID(0) B6 B5 B4 B3 B2 B1 B0
    byte two = value & 0x7F; // low 7 bit
    Serial.write(one);
    Serial.write(two);
    delay(3);
  }
}
