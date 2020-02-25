int color [0], duration[0];
int red = 9;
int green = 10;
int blue = 11;

void setup() {
  // put your setup code here, to run once:
 // pinMode(YELLOW, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(red, HIGH);   // turn the LED off (HIGH is the voltage level)
  digitalWrite(green, HIGH);   // turn the LED off (HIGH is the voltage level)
  digitalWrite(blue, HIGH);   // turn the LED off (HIGH is the voltage level)
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Type 1 for red\n Type 2 for green \n Type 3 for blue");
  while (!Serial.available());
  color[0] = Serial.read();

  Serial.println("Type the number of seconds");
  while (!Serial.available());
  duration[0] = Serial.read();

  if (color[0] > 3){ 
    Serial.println("invalid color");
  }else{
    turnOn(color[0],duration[0]);
  }
  
}
void turnOn(int cntrl[0], int drtn[0]){
 int color;

 switch(cntrl[0]){
  case 1: color = red;
    break;
  case 2: color = blue;
    break;
  case 3: color = green;
    break;
  default: color;
    break;  
  };
  digitalWrite(color, LOW);
  delay(drtn[0]*1000);
  digitalWrite(color, HIGH);
  
}
