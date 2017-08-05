const int buttonIN = 3;
const int inA = 7;
const int inB = 8;
const int PWM_mot = 9;


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


void setup() {
    pinMode(buttonIN, INPUT);
    pinMode(inA, OUTPUT);
    pinMode(inB, OUTPUT);
    Serial.begin(9600);

    stop();
}


int flag = 0;
int i = 0;
void loop() {
    int val = digitalRead(buttonIN);
    Serial.println(val);
    if (val == HIGH && flag == 0) {
        cw();
        flag = 1;
    } else if (val == HIGH && flag == 2) {
        cw();
        flag = 3;
    } else if (val == HIGH && (flag == 1 || flag == 3)) {
        // do nothing
    } else {
        stop();
        if (flag == 0 || flag == 1) {
            flag = 2;
        } else if (flag == 2 || flag == 3) {
            flag = 0;
        }
    }
}