/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL3nW1QfkfN"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "9BtHsdcEmc8dXqigdhKcH9xKz5H1pWMO"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <NewPing.h> // Library to interface with ultrasonic sensor

// Your WiFi credentials
char ssid[] = "JAY";
char pass[] = "87654321";

// Ultrasonic Sensor pins
#define TRIGGER_PIN 5
#define ECHO_PIN 18

NewPing sonar(TRIGGER_PIN, ECHO_PIN, 400); // Maximum distance set to 400 cm

void setup()
{
  // Debug console
  Serial.begin(9600);
  
  // Blynk connection
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  // Initialize sensor pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop()
{
  Blynk.run();
  measureDistance();
}

void measureDistance()
{
  // Measure distance using ultrasonic sensor
  unsigned int distance = sonar.ping_cm();
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Send distance to Blynk app
  Blynk.virtualWrite(V0, distance);
  
  delay(1000); // Update every 1 second
}
