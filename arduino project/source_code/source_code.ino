int l1 = 5; // green led
int l2 = 4; // orange led
int l3 = 3; // red led
int buzzer = 6; // buzzer
int trig = 9;
int echo = 7;
void setup()
{
  Serial.begin(9600);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int a = pulseIn(echo, HIGH);
  int distance = a * 0.0343 / 2;
  Serial.print("Value of US sensor");
  Serial.println(distance);

  if (distance < 50)
  {
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
    digitalWrite(buzzer, LOW);


  }
  if (distance < 30)
  {
    digitalWrite(l2, HIGH);
    digitalWrite(l1, LOW);
  }
  if (distance < 10)
  {
    digitalWrite(l2, LOW);
    digitalWrite(l1, LOW);
    digitalWrite(l3, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(150);
    digitalWrite(buzzer, HIGH);
    delay(150);
    digitalWrite(buzzer, LOW);
    delay(150);
  }

}
