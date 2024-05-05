#include <Servo.h>
#include <ServoSmooth.h>

// Define servo objects
Servo baseServo;
Servo armServo;
Servo gripServo;
Servo rotateGripServo;
ServoSmooth servoSmooth;



// Define color sensor pins
/*#define S0 4
#define S1 5
#define S2 2
#define S3 7
#define sensorOut 8

// Variables for Color Pulse Width Measurements
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

void sensorInit() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

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
}*/

void moveSmoothServo(int upAndDownPosition, int delayTime = 0) {
  servoSmooth.setTargetDeg(upAndDownPosition);
  while (!servoSmooth.tick())
    ;
  Serial.println("Servo 20K 1 moved to position: " + (String)upAndDownPosition);
  delay(delayTime);
}

void moveAllServos(int basePosition, int armPosition, int gripPosition, int rotateGripPosition, int upAndDownPosition, int delayTime = 0) {

  baseServo.write(basePosition);
  Serial.print("Base moved ");
  delay(delayTime);

  moveSmoothServo(upAndDownPosition, 2000);
  Serial.print("Servo 20kg moved ");

  armServo.write(armPosition);
  Serial.print("Arm moved ");
  delay(delayTime);

  rotateGripServo.write(rotateGripPosition);
  Serial.print("Rotate moved ");

  // gripServo.write(gripPosition);
  // Serial.print("Grip moved ");
  // delay(delayTime);
}




void moveBase(int basePosition, int delayTime = 0) {
  baseServo.write(basePosition);
  Serial.print("Base moved  ");
  delay(delayTime);
}

void moveArm(int armPosition, int delayTime = 0) {
  armServo.write(armPosition);
  Serial.print("Arm moved  ");
  delay(delayTime);
}

void moveRotate(int rotatePosition, int delayTime = 0) {
  rotateGripServo.write(rotatePosition);
  Serial.print("Rotate moved  ");
  delay(delayTime);
}

void grip(int gripPosition, int delayTime = 0) {
  gripServo.write(gripPosition);
  Serial.print("Grip moved  ");
  delay(delayTime);
}



void goToRed() {
  Serial.println();
  Serial.println("Red detected  ");
  int armPositionPick = 120;
  moveArm(armPositionPick, 2000);
  int upAndDownPosition = 30;
  moveSmoothServo(upAndDownPosition, 2000);
  int basePositionPick = 20;
  moveBase(basePositionPick, 2000);
  armPositionPick = 150;
  moveArm(armPositionPick, 2000);
}

/*void goToGreen() {
  Serial.println();
  Serial.println("Green detected  ");
  int armPositionPick = 90;
  moveArm(armPositionPick, 2000);
  int basePositionPick = 170;
  moveBase(basePositionPick, 2000);
  armPositionPick = 50;
  moveArm(armPositionPick, 2000);
}

void goToBlue() {
  Serial.println();
  Serial.println("Blue detected  ");
  int armPositionPick = 90;
  moveArm(armPositionPick, 2000);
  int basePositionPick = 90;
  moveBase(basePositionPick, 2000);
  armPositionPick = 50;
  moveArm(armPositionPick, 2000);
}*/


// Function to detect the color & move the SERVOs to the required location
/*void getColor() {
  // Read Red Pulse Width
  int redCounter = 0;
  int blueCounter = 0;
  int greenCounter = 0;

  for (int i = 0; i < 5; ++i) {
    redPW = getRedPW();
    delay(200);  // Delay to stabilize sensor
    // Read Green Pulse Width
    greenPW = getGreenPW();
    delay(200);  // Delay to stabilize sensor
    // Read Blue Pulse Width
    bluePW = getBluePW();
    delay(200);  // Delay to stabilize sensor

    if ((redPW < greenPW && redPW < bluePW))  //Detect Red Color
      redCounter++;
    else if ((greenPW <= redPW && greenPW <= bluePW))  //Detect Green Color
      greenCounter++;
    else if ((bluePW < redPW && bluePW < greenPW))  //Detect Blue Color
      blueCounter++;
    Serial.println("///////////////////////////////////////////");
    Serial.print("Loop number: ");
    Serial.println(i + 1);
    Serial.print("redCounter: ");
    Serial.println(redCounter);
    Serial.print("greenCounter: ");
    Serial.println(greenCounter);
    Serial.print("blueCounter: ");
    Serial.println(blueCounter);
    Serial.println("///////////////////////////////////////////");
  }

  if (redCounter > greenCounter && redCounter > blueCounter)
    goToRed();
  else if (greenCounter > redCounter && greenCounter > blueCounter)
    goToGreen();
  else if (blueCounter > redCounter && blueCounter > greenCounter)
    goToBlue();
}*/


// Function to attach servos to pins
void attachServos() {
  baseServo.attach(9);         // Attach baseServo to pin 9
  armServo.attach(10);         // Attach armServo to pin 10
  gripServo.attach(6);         // Attach gripServo to pin 11
  rotateGripServo.attach(11);  // Attach rotateGripServo to pin 6
}

void attachServos20K() {
  servoSmooth.attach(5, 400, 2400);  // Attach servo to pin 5
  servoSmooth.setAutoDetach(true);
  servoSmooth.setSpeed(100);  // Set speed value
  servoSmooth.setAccel(0);
}

// Function to initialize servo positions
void initializePositions() {
  int basePositionInitial = 50;
  int armPositionInitial = 90;
  int gripPositionInitial = 30;
  int rotateGripPositionInitial = 90;
  int upAndDownPosition = 0;
  moveAllServos(basePositionInitial, armPositionInitial, gripPositionInitial, rotateGripPositionInitial, upAndDownPosition, 2000);
}

void goToLaundry() {
  int basePositionLaundry = 0;
  int armPositionLaundry = 150;
  int gripPositionLaundry = 30;
  int rotateGripPositionLaundry = 90;
  int upAndDownPosition = 100;
  moveAllServos(basePositionLaundry, armPositionLaundry, gripPositionLaundry, rotateGripPositionLaundry, upAndDownPosition, 1000);
}

void pickAndDetectAndRelease() {

  int gripPositionPick = 90;
  grip(gripPositionPick, 2000);
  goToRed();
  //getColor();
  gripPositionPick = 30;
  grip(gripPositionPick, 3000);
}

void makeLaundry() {
  goToLaundry();
  delay(2000);
  pickAndDetectAndRelease();
}



void setup() {
  Serial.begin(9600);
  //sensorInit();
  attachServos();
  attachServos20K();
  initializePositions();
  delay(3000);
  makeLaundry();
  //delay(2000);
}

void loop() {
  // // Main code will go here
  // makeLaundry();
  // delay(2000);
}