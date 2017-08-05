#include <Servo.h>

Servo servo1, servo2;

void setup() {
    servo1.attach(9);
    servo2.attach(10);
}

void mysleep(int n) {
    if (n >= 80 && n <= 100) {
        /* delay(1000UL * 60UL * 50UL); */
        delay(1000);
    } else {
        /* delay(1000UL * 60UL * 10UL); */
        delay(1000);
    }
}

int i = 0;
void loop() {
    /* servo1.write(i % 95 + 45); */
    for (i = 45; i <= 135; i += 5) {
        servo1.write(i);
        servo2.write(180 - i);
        mysleep(i);
    }
    for (i = 135; i >= 45; i -= 5) {
        servo1.write(i);
        servo2.write(180 - i);
        mysleep(i);
    }
}
