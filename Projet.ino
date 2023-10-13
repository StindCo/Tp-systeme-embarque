
#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>


Adafruit_LiquidCrystal lcd_1(0);

int pos = 0;

Servo servo_9;
int moisture = 0;

void setup()
{
  lcd_1.begin(16, 2);

  lcd_1.print("Humidity : ");
  servo_9.attach(6, 500, 2500);
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  
  digitalWrite(A0, HIGH);
  delay(10); 
  moisture = analogRead(A1);
  
  lcd_1.setCursor(0, 1);
  lcd_1.print(moisture);
  lcd_1.setBacklight(1);
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  if (moisture < 200) {
    digitalWrite(12, HIGH);
     servo_9.write(90);
  } else {
    if (moisture < 400) {
      digitalWrite(11, HIGH);
       servo_9.write(60);
    } else {
      if (moisture < 600) {
        digitalWrite(10, HIGH);
        servo_9.write(45);
      } else {
        if (moisture < 800) {
          digitalWrite(9, HIGH);
          servo_9.write(30);
        } else {
          digitalWrite(8, HIGH);
          servo_9.write(0);
        }
      }
    }
  }
  delay(100); 
}
