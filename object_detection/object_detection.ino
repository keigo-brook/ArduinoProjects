/*
 * Infrared obstacle sensor module test project
 * tutorial url: http://osoyoo.com/?p=679
 */

int buttonpin=3;
int val;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonpin,INPUT);
}

void loop()
{
  val=digitalRead(buttonpin);
  if(val == HIGH) {
    Serial.println("HIGH");
  } else {
    Serial.println("LOW");
  }
}