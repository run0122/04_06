#include <TimerOne.h>
#include <Servo.h>
#include "pitches.h"

const int trigPin = 4;
const int echoPin = 5;
const int led = 10;
const int buzzer = 9;
const int button = 7;

bool funcState = false;

float duration, distance, distance2;

// const int melody[] = {
//   262,
//   294,
//   330,
//   349,
//   393,
//   440,
//   494,
//   523,
// };

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

Servo myservo;

int val;

void setup() {
  // Timer1.initialize();
  // Timer1.pwm(buzzer, 0);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);

  myservo.attach(6); 
}

void loop() {
  int reading = digitalRead(button);
  
  if (reading == HIGH) {
    funcState = !funcState;
    delay(100);
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;

  // if (funcState == true && distance < 15 && distance > 2.5) {
  //   distance2 = map(distance, 2.5, 15, 200, 0);

  //   Timer1.pwm(buzzer, 0);

  //   digitalWrite(led, HIGH);
  //   Timer1.setPwmDuty(buzzer, 512);
  //   Timer1.setPeriod(1000000 / 262);
  //   delay(200 - distance2);
  //   digitalWrite(led, LOW);
  //   Timer1.setPwmDuty(buzzer, 0);
  //   delay(200 - distance2);

  // } 
  if (funcState == true && distance < 15 && distance > 2.5) {
    distance2 = map(distance, 2.5, 15, 200, 0);
    val = map(distance, 2.5, 15, 15, 165);
    // Timer1.pwm(buzzer, 0);

    digitalWrite(led, HIGH);
    // Timer1.setPwmDuty(buzzer, 512);
    // Timer1.setPeriod(1000000 / 262);
    tone(buzzer, 196);
    myservo.write(val);
    delay(200 - distance2);
    digitalWrite(led, LOW);
    // Timer1.setPwmDuty(buzzer, 0);
    tone(buzzer, 196);
    delay(200 - distance2);

  } else if (funcState == true && distance < 2.5) {
    digitalWrite(led, HIGH);
    // Timer1.setPwmDuty(buzzer, 512);
    // for (int note = 0; note < 8; note++) {
    //   Timer1.setPeriod(1000000 / melody[note]);
    //   delay(500);
    // }
    // for (int thisNote = 0; thisNote < 8; thisNote++) {
    //   int noteDuration = 1000 / noteDurations[thisNote];
      
    //   tone(buzzer, melody[thisNote], noteDuration);
      
    //   int pauseBetweenNotes = noteDuration * 1.30;
    //   delay(pauseBetweenNotes);
    //   noTone(buzzer);
    // }
  } else {
    digitalWrite(led, LOW);
    noTone(buzzer);
    // Timer1.setPwmDuty(buzzer, 0);
  }
  // Serial.print("Distance: ");
  // Serial.println(distance);
  // delay(100);
}








// #include <TimerOne.h>
// #include "pitches.h"

// const int trigPin = 4;
// const int echoPin = 5;
// const int led = 10;
// const int buzzer = 9;
// const int button = 7;

// bool funcState = false;

// float duration, distance, distance2;

// // const int melody[] = {
// //   262,
// //   294,
// //   330,
// //   349,
// //   393,
// //   440,
// //   494,
// //   523,
// // };

// int melody[] = {
//   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
// };

// int noteDurations[] = {
//   4, 8, 8, 4, 4, 4, 4, 4
// };

// void setup() {
//   Timer1.initialize();
//   Timer1.pwm(buzzer, 0);

//   pinMode(trigPin, OUTPUT);
//   pinMode(echoPin, INPUT);
//   pinMode(led, OUTPUT);
//   pinMode(button, INPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   int reading = digitalRead(button);
  
//   if (reading == HIGH) {
//     funcState = !funcState;
//     delay(100);
//   }

//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   duration = pulseIn(echoPin, HIGH);
//   distance = (duration * .0343) / 2;

//   if (funcState == true && distance < 15 && distance > 2.5) {
//     distance2 = map(distance, 2.5, 15, 200, 0);

//     Timer1.pwm(buzzer, 0);

//     digitalWrite(led, HIGH);
//     Timer1.setPwmDuty(buzzer, 512);
//     Timer1.setPeriod(1000000 / 262);
//     delay(200 - distance2);
//     digitalWrite(led, LOW);
//     Timer1.setPwmDuty(buzzer, 0);
//     delay(200 - distance2);
//   } else if (funcState == true && distance < 2.5) {
//     digitalWrite(led, HIGH);
//     // Timer1.setPwmDuty(buzzer, 512);
//     // for (int note = 0; note < 8; note++) {
//     //   Timer1.setPeriod(1000000 / melody[note]);
//     //   delay(500);
//     // }
//     for (int thisNote = 0; thisNote < 8; thisNote++) {
//       int noteDuration = 1000 / noteDurations[thisNote];
      
//       tone(buzzer, melody[thisNote], noteDuration);
      
//       int pauseBetweenNotes = noteDuration * 1.30;
//       delay(pauseBetweenNotes);
//       noTone(buzzer);
//     }
//   } else {
//     digitalWrite(led, LOW);
//     Timer1.setPwmDuty(buzzer, 0);
//   }
//   // Serial.print("Distance: ");
//   // Serial.println(distance);
//   // delay(100);
// }

