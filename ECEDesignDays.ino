// ECE Design Days
// Group 26
// Mon Mar 4, 2019

#include <Servo.h>

Servo phi;          // Lower servo
Servo theta;        // Upper servo
float threshold = 0.01;

void setup() {

  // Debugging on Serial monitor
  Serial.begin(9600);
  Serial.println("Begin:");

  // Attach servos to pins
  phi.attach(3);
  theta.attach(9);

  // Delay 5 seconds
  delay(5000);

}

// Initialize the solar panel to face one direction of the horizon
int vertical = 175;
// int horizontal = 0;

void loop() {

  // Read and calculate voltage from sensors
  int sensor1 = analogRead(A1);
  float voltage1 = sensor1 * (5.0 / 1023.0);
  int sensor2 = analogRead(A3);
  float voltage2 = sensor2 * (5.0 / 1023.0);
  int sensor3 = analogRead(A5);
  float voltage3 = sensor3 * (5.0 / 1023.0);

  // Sensor reading debugging
  Serial.print("Voltage 1: ");
  Serial.println(voltage1);
  Serial.print("Voltage 2: ");
  Serial.println(voltage2);
  Serial.print("Voltage 3: ");
  Serial.println(voltage3);
  Serial.println();

  // Servo rotation logic

  // Vertical rotation logic
  if (abs(voltage1 - voltage2) < threshold)
  {
    Serial.println(voltage1 - voltage2);
    Serial.println("Do nothing");
  }
  else if ((voltage1 - voltage2) > threshold)
  {
    if (vertical > 0)
    {
      vertical--;
    }
    Serial.println("voltage1 < voltage3");
  }
  else if ((voltage2 - voltage1) > threshold)
  {
    if (vertical < 180)
    {
      vertical++;
    }
    Serial.println("voltage1 > voltage3");
  }

  Serial.println(vertical);

  theta.write(vertical);

/*
  // Horizontal rotation logic
  if (voltage2 < voltage1 || voltage2 < voltage3)
  {
    if (voltage1 < voltage3)
    {
      phi.write(-1);
      Serial.println("voltage1 < voltage3");
    }
    else if (voltage1 > voltage3)
    {
      phi.write(1);
      Serial.println("voltage1 > voltage3");
    }
  }
*/
  // Loop delay
  delay(100);

}
