#include <Servo.h>  // Include the servo library

// Define color sensor pins
#define S0 22
#define S1 23
#define S2 24
#define S3 25
#define sensorOut 26


// Define led pins
#define led_blue 9
#define led_green 10
#define led_red 11

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;


void setup() {
  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(led_blue, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_white, OUTPUT);
  pinMode(led_yellow, OUTPUT);

  // Set Pulse Width scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // Set Sensor output as input
  pinMode(sensorOut, INPUT);

  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {
  redPW = getRedPW();      // Read Red Pulse Width
  delay(200);              // Delay to stabilize sensor
  greenPW = getGreenPW();  // Read Green Pulse Width
  delay(200);              // Delay to stabilize sensor
  bluePW = getBluePW();    // Read Blue Pulse Width
  delay(200);              // Delay to stabilize sensor
  GetColor();

  // Print output to Serial Monitor
  Serial.print("Red PW = ");
  Serial.print(redPW);
  Serial.print(" - Green PW = ");
  Serial.print(greenPW);
  Serial.print(" - Blue PW = ");
  Serial.println(bluePW);
}

//------------------------------------------------------------------------------------/*FUNCTIONS*/------------------------------------------------------------------------------

// Function to read Red Pulse Widths
int getRedPW() {
  // Set sensor to read Red only
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to read Green Pulse Widths
int getGreenPW() {
  // Set sensor to read Green only
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}


// Function to read Blue Pulse Widths
int getBluePW() {
  // Set sensor to read Blue only
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;
}

// Function to detect the color & move the SERVOs to the required location
void GetColor() {
  if ((redPW < greenPW && redPW < bluePW)) {  //Detect Red Color
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, LOW);
    Serial.println("Red");
  }
  else if ((greenPW < redPW) && (greenPW < bluePW))  //Detect Green Color
  {
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_blue, LOW);
    Serial.println("Green");
  }
  else if ((bluePW < redPW && bluePW < greenPW))  //Detect Blue Color
  {
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, HIGH);
    Serial.println("Blue");
  }
}