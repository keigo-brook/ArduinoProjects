int analog_sensor = A1;
int digit_sensor = 8;
int ledPin = 13;
int analogValue;
int digitValue;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(digit_sensor, INPUT);
    Serial.begin(9600);
}

void loop() {
    analogValue = analogRead(analog_sensor);
    digitValue = digitalRead(digit_sensor);
    Serial.println(analogValue, DEC);
    if(digitValue == HIGH){
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}