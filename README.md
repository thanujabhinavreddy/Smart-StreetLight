Smart Street Light Controller

An automated, energy-efficient street lighting system prototype developed using Arduino, LDR, and IR sensors. This project aims to reduce power consumption in urban areas by dynamically adjusting light intensity based on environmental conditions and human activity.

📌 Project Overview

Conventional street lighting systems operate at full intensity throughout the night, leading to excessive energy consumption. This project presents a Smart Street Light Controller that:

Automatically switches OFF during the day.

Operates at a dimmed (low-power) intensity during the night when no traffic is present.

Switches to full brightness only when motion (pedestrian or vehicle) is detected.

🚀 Features

LDR-Based Automation: Uses a Light Dependent Resistor to detect sunrise and sunset.

Motion Detection: Infrared (IR) sensors detect movement to trigger full illumination.

PWM Control: Pulse-Width Modulation is used to transition smoothly between dim and full brightness states.

Energy Efficiency: Significant reduction in electricity wastage compared to traditional manual systems.

🛠️ Hardware Components

Component

Description

Arduino Nano

The central microcontroller unit.

LDR Sensor

Detects ambient light intensity (Day/Night).

IR Sensors (x4)

Detects motion on the road.

LEDs (x4)

Represents the street lamps.

Resistors

$10k\Omega$ for LDR, $220\Omega$ for LED protection.

Power Supply

5V DC.

📟 Circuit Logic

Daytime: LDR resistance is low $\rightarrow$ Arduino keeps LEDs OFF.

Nighttime (No Motion): LDR resistance is high $\rightarrow$ Arduino sets LEDs to DIM intensity ($60/255$ PWM).

Nighttime (Motion Detected): IR Sensor triggers $\rightarrow$ Arduino sets specific LED to FULL intensity ($255/255$ PWM).

💻 Source Code

// Smart Street Light (4-lamp version)
// Arduino Nano + LDR + IR Sensors + LEDs

const int LDR_PIN = A0;
const int IR_SENSOR_PINS[4] = {2, 3, 4, 5}; 
const int LED_PINS[4] = {3, 5, 6, 9}; // PWM pins

const int LDR_THRESHOLD_NIGHT = 400; 
const int LED_DIM = 60; 
const int LED_FULL = 255;

void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(IR_SENSOR_PINS[i], INPUT_PULLUP);
    pinMode(LED_PINS[i], OUTPUT);
    analogWrite(LED_PINS[i], 0);
  }
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);
  bool isNight = (ldrValue < LDR_THRESHOLD_NIGHT);

  if (!isNight) {
    for (int i = 0; i < 4; i++) {
      analogWrite(LED_PINS[i], 0);
    }
  } else {
    for (int i = 0; i < 4; i++) {
      analogWrite(LED_PINS[i], LED_DIM);
    }
    for (int i = 0; i < 4; i++) {
      if (digitalRead(IR_SENSOR_PINS[i]) == LOW) { 
        analogWrite(LED_PINS[i], LED_FULL);
      }
    }
  }
  delay(100);
}


👥 Authors

This project was developed by:

Manvendra Singh Rao (Roll No: N-58)

M. Thanuj Abhinav Reddy (Roll No: N-59)

Meghana S. B. (Roll No: N-60)

🎓 Acknowledgments

Institution: CMR Institute of Technology (CMRIT), Bengaluru.

Department: Basic Sciences (Innovation & Design Thinking Laboratory).

Internal Guide: Dr. Ashutosh Srivastava, Professor, Dept. of ECE.

HOD: Dr. Raveesha K H, Dept. of Physics, CMRIT.

📄 License

This project is for educational purposes under the VTU (Visvesvaraya Technological University) curriculum.
