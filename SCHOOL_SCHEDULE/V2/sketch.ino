#include "Scheduler.h"

// Define the chip select pin for the SD card and the LED pin for the alarm
const int chipSelect = 8;
const int ledPin = 7;

// Define the schedule file name
String scheduleFileName = "dacian.csv";

// Define the RingingTime (in seconds) when the alarm will stay on
unsigned long ringingTime = 10; 

// Create a Scheduler object
Scheduler scheduler(chipSelect, ledPin, scheduleFileName, ringingTime);

void setup() {
  // Start serial communication
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }

  // Initialize the scheduler (RTC, SD card, LED)
  scheduler.init();
}

void loop() {
  // Update the scheduler to check for events and alarms
  scheduler.update();

  // Delay to avoid using too much CPU
  delay(5000); // 5 second
}
