float a_in;
float temp_c = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    a_in = analogRead(0);
    
    temp_c = ((5 * a_in) / 1024) * 100;
    Serial.println(temp_c);
    delay(1000);
}