/*
 * Akiva Brookler
 * 10/9/18
 * Mr. Gomez
 * Engineering 10
 */
 
//libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//sets up lcd with ahardware adapter
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//variable declaration
int red = 9, green = 10, blue = 11;

void setup() {
  //initializes lcd
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  //sets pins as outputs
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(12,INPUT);
  //turns off leds
  digitalWrite(red, HIGH);  
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  //intialize serial
  Serial.begin(9600);
}

void loop() {  
  if (inches() > 14){
    off();
    analogWrite(blue, brightness());
  }else if (inches() > 7){
    off();
    analogWrite(green, brightness());  
  }else{
    off();
    analogWrite(red, brightness());
  }
  delay(500);
  lightInchesLcd();
}
//turns off leds
void off(){
  digitalWrite(red, HIGH);  
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}
//prints to lcd light and inches
void lightInchesLcd(){
  lcd.setCursor(0,0);
  lcd.print(analogRead(0));
  lcd.setCursor(5,0);
  lcd.print("brightness");
  lcd.setCursor(0,1);
  lcd.print(inches());
  lcd.setCursor(5, 1);
  lcd.print("inches");
  delay(500);
  lcd.clear();
}
//find distance (inches)
int inches(){
  long duration, inches;
  digitalWrite(13,LOW);
  delayMicroseconds(2);
  digitalWrite(13, HIGH);
  delayMicroseconds(5);
  digitalWrite(13,LOW);
  duration = pulseIn(12, HIGH);
  inches = duration / 74 / 2;
  Serial.print("Inches:");
  Serial.println(inches);
  delay(200);
  return inches;
}
//calculates brighness based on photoRead
int brightness(){
  int intensity = analogRead(0);
  Serial.print("Light Intensity:");
  Serial.println(intensity);
  return map(intensity, 25, 150, 255, 0);
}
