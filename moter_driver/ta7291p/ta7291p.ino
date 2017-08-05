const int inA = 7;
const int inB = 8;
const int PWM_mot = 9;

void setup() {
    pinMode(inA, OUTPUT);
    pinMode(inB, OUTPUT);
}

void stop() {
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);
    delay(100);
}

void cw() {
    stop();
    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
    analogWrite(PWM_mot, 100);
    delay(100);
}

void ccw() {
    stop();
    digitalWrite(inA, LOW);
    digitalWrite(inB, HIGH);
    analogWrite(PWM_mot, 100);
    delay(100);
}



void loop() {
    cw();
    delay(6000);
    ccw();
    delay(6000);
    stop();
    delay(2000);

}
