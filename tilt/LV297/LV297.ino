float a_in;
int d_in;

void setup() {
    Serial.begin(9600);
}

void loop() {
    a_in = analogRead(0);
    d_in = digitalRead(0);
    Serial.println(a_in);
    Serial.println(d_in);
    delay(100);
}