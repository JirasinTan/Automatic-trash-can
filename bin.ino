#include <Servo.h>
Servo myservo; //ประกาศตัวแปรแทน Servo
const int metal = D1;
int analogPin = A0;
int val = 0;
void setup() {
myservo.attach(2);
Serial.begin(9600);
}
void loop() {
val = analogRead(analogPin); //อ่านค่าสัญญาณ analog ขา A0
Serial.print("val = "); // พิมพ์ข้อความส่งเข้าคอมพิวเตอร์"val = "
Serial.println(val); // พิมพ์ค่าของตวัแปร val
delay(1000);
if (val < 70) {
servo_Left();
}
int sensorValue = digitalRead(metal);
if (sensorValue == HIGH) {
servo_Right ();
Serial.println("Object Detected");
delay(500);
}
else {
Serial.println("no Object");
delay(500);
}
41
delay(100);
}
void servo_Left () {
myservo.write(90); // สั่งให้Servo หมุนไปองศาที่ 90
delay(500);
myservo.write(0); // สั่งให้Servo หมุนไปองศาที่ 0
delay(500);
myservo.write(90); // สั่งให้Servo หมุนไปองศาที่ 90
delay(500);
}
void servo_Right () {
myservo.write(90); // สั่งให้Servo หมุนไปองศาที่ 90
delay(500);
myservo.write(180); // สั่งให้Servo หมุนไปองศาที่ 180
delay(500);
myservo.write(90); // สั่งให้Servo หมุนไปองศาที่ 90
delay(500 );
}