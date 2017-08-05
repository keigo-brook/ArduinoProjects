const int inputPin = 0;
const int ledPin = 13;

void setup() {
    pinMode(inputPin, INPUT);
}

void loop() {
    int val = digitalRead(inputPin);
    if (val == HIGH) {
        digitalWrite(ledPin, LOW);
    } else {
        digitalWrite(ledPin, HIGH);
    }
}