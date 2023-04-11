#include <TimerOne.h>

const int trigPin = 4;
const int echoPin = 5;
const int led = 10;
const int buzzer = 9;
const int button = 7;

bool funcState = false;

float duration, distance;

void setup() {
  Timer1.initialize();
  Timer1.pwm(buzzer, 0);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;

  int reading = digitalRead(button);

  if(reading==HIGH){
    funcState = !funcState;
  }

  if (funcState == true && distance < 10) {
    digitalWrite(led, HIGH);
    Timer1.setPwmDuty(buzzer, 512);
    Timer1.setPeriod(1000000 / 262);
  } else {
    digitalWrite(led, LOW);
    Timer1.setPwmDuty(buzzer, 0);
  }
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println((String)"funcState: "+funcState);
  delay(100);
}