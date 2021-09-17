//cite this code as jackton sabayi 
#include <Wire.h> 
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

Servo myservo;
int sensorPin = A0;   
int sensorPinn = A2;
int sensorValue = 0;  
int sensorValu =  0;

int pos = 0;
//float sensorValue = 0.0; 
//float sensorValu = 0.0;

void setup()
{ // initialize the lcd 
 lcd.init();                      
 // Print a message to the LCD.
  lcd.backlight();
  lcd.clear();
  myservo.attach(9);
  myservo.write(0);
  
}

void fast() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(3);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(3);                       // waits 15 ms for the servo to reach the position
  }
}

void medium() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(12);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(12);                       // waits 15 ms for the servo to reach the position
  }
}

void slow() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 15 ms for the servo to reach the position
  }
}
 
void loop()
{sensorValue = analogRead(sensorPin);
 sensorValu = analogRead(sensorPinn);

 //control wiper using resistive sensor
if (sensorValu<=430){
fast();
}
else { myservo.write(0);}
delay(30);
if (sensorValu>430 && sensorValu<=550){
medium();
}
else { myservo.write(0);}
delay(30);
if (sensorValu>550 && sensorValu<=890){
slow();
}
else { myservo.write(0);} 
delay(30);

//control servo using optical sensor

//if (sensorValue>550 && sensorValu>890 ){
//fast(); // takes any state either fast medium or slow
//}
//else { myservo.write(0);} 

// sensorValue = (analogRead(sensorPin)*5)/1023;
// sensorValu = (analogRead(sensorPinn)*5)/1023;
  lcd.setCursor(0,0);
  lcd.print("Opt sensor: ");
  lcd.print( sensorValue);
  lcd.setCursor(0,1);
  lcd.print("Res sensor: ");
  lcd.print( sensorValu);
  delay(1000); 
}
