# 04_06

<hr/>

## 1. 초음파 센서

```
bool funcState = false;

int reading = digitalRead(button);

if (reading == HIGH) {
    funcState = !funcState;
    delay(100);
  }
```
위와 같이 funcState가 true일 때만 초음파 센서가 작동하도록 했습니다.
---

```
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
```
초음파 센서는 이와 같이 작동합니다.
---

```
  if (funcState == true && distance < 15 && distance > 2.5) {
    distance2 = map(distance, 2.5, 15, 200, 0);

    Timer1.pwm(buzzer, 0);

    digitalWrite(led, HIGH);
    Timer1.setPwmDuty(buzzer, 512);
    Timer1.setPeriod(1000000 / 262);
    delay(200 - distance2);
    digitalWrite(led, LOW);
    Timer1.setPwmDuty(buzzer, 0);
    delay(200 - distance2);
  } 
```
funcState가 참이고, 거리가 15에서 2.5 사이일 때 가까워 질수록 LED와 Buzzer의 빈도가 빨라지도록 구현했습니다.
---
```
distance2 = map(distance, 2.5, 15, 200, 0);
```
**map()함수를 통해서 2.5와 15 사이의 값을 0과 200으로 변환해주었고 이를 delay 함수에 적용하기 위해서 distance의 높낮이를 반대로 변환했습니다.**

```
else if (funcState == true && distance < 2.5) {
    digitalWrite(led, HIGH);
    
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      
      tone(buzzer, melody[thisNote], noteDuration);
      
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(buzzer);
    }
  } 
```
**distance가 2.5보다 적으면 충분히 가깝다는 뜻이므로, LED의 점멸을 멈추고 그냥 켜지게 변환해주었습니다. 그리고 toneMelody를 활용하여 특정한 멜로디가 연주되도록 구현하였습니다.**
```
else {
    digitalWrite(led, LOW);
    Timer1.setPwmDuty(buzzer, 0);
  }
```
**그 외의 값은 LED와 Buzzer가 작동하지 않도록 했습니다.**

<hr/>
