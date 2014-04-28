// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
Servo myservo2;

int potpin = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;
int val;    // variable to read the value from the analog pin 
int val2;

const int numReadings = 100;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;



void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(3);
  
  Serial.begin(9600);                   
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;  
} 

void loop() 
{ 
  total= total - readings[index];         
  readings[index] = analogRead(potpin); 
  total= total + readings[index];        
  index = index + 1;                    

  if (index >= numReadings)              
    index = 0;                           
  average = total / numReadings;         
  Serial.println(average);   
  
  
  val = analogRead(average);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 170);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);  // sets the servo position according to the scaled value 
  delay(15);
  val2 = analogRead(potpin2);
  val2 = map(val2 ,0 ,1023, 0,170);
  myservo2.write(val2);
  delay(15);                           // waits for the servo to get there 

  Serial.println(val, val2);
} 

