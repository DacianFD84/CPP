#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <SD.h>

// SD card chip select pin
const int chipSelect = 8;

// LED pin for alarm
const int ledPin = 7;

// Declare variables for date, time, and timestamp
String date, timeFormatted;
unsigned long Timestamp;

// Declare previous time variables to update once per second
int prevHour = -1, prevMinute = -1, prevSecond = -1;
bool alarmActive = false; // Flag to track if the alarm is already active

// Declare the RingingTime variable (in seconds)
unsigned long RingingTime = 10; // The alarm stays on for 10 seconds

// Initialize RTC
RTC_DS3231 rtc;

// Declare the filename variable
String scheduleFileName = "dacian.csv";

// Store the last triggered time (to prevent triggering again in the same minute)
String lastTriggeredTime = "";

void setup() {
  // Start serial communication
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }

  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("RTC not found!");
    while (1); // Stop execution if RTC is not found
  }

  // Initialize SD card
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Serial.println("SD card initialized!");

  // Test opening the schedule file
  File testFile = SD.open(scheduleFileName);
  if (testFile) {
    Serial.println("Schedule file opened successfully!");
    testFile.close();
  } else {
    Serial.println("Error opening schedule file!");
  }

  // Initialize LED pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.println("System Initialized!");
}

void loop() {
  // Get the current time from the RTC
  DateTime now = rtc.now();
  int rtcHour = now.hour();
  int rtcMinute = now.minute();
  int rtcSecond = now.second();

  // Format the time as HH:MM
  String hour = formatWithLeadingZero(rtcHour);
  String minute = formatWithLeadingZero(rtcMinute);
  String second = formatWithLeadingZero(rtcSecond);
  timeFormatted = hour + ":" + minute;

  // Format the date as dd/mm/yy
  date = formatWithLeadingZero(now.day()) + "/" + formatWithLeadingZero(now.month()) + "/" + String(now.year()).substring(2, 4);

  // Print the current time and date for debugging
  Serial.print("Current Time: ");
  Serial.println(timeFormatted);
  Serial.print("Current Date: ");
  Serial.println(date);

  // Update time if it changes
  if (rtcHour != prevHour || rtcMinute != prevMinute || rtcSecond != prevSecond) {
    prevHour = rtcHour;
    prevMinute = rtcMinute;
    prevSecond = rtcSecond;
  }

  // Check the schedule for events and trigger if needed
  if (!alarmActive) {
    checkSchedule(timeFormatted, now.dayOfTheWeek());
  }

  delay(1000); // Check every second
}

// Format integers with leading zeros for display
String formatWithLeadingZero(int value) {
  return value < 10 ? "0" + String(value) : String(value);
}

// Check the schedule for matching events
void checkSchedule(String currentTime, int currentDay) {
  // Open the schedule file
  File scheduleFile = SD.open(scheduleFileName);
  if (!scheduleFile) {
    Serial.println("Error opening schedule file!");
    return;
  }

  Serial.println("Checking Schedule...");

  char lineBuffer[128];
  int currentHour = currentTime.substring(0, 2).toInt();
  int currentMinute = currentTime.substring(3, 5).toInt();

  while (scheduleFile.available()) {
    readLine(scheduleFile, lineBuffer, sizeof(lineBuffer));

    // Parse the line into time, event, and days
    String line = String(lineBuffer);
    String eventTime = getField(line, 0, ',');
    String eventName = getField(line, 1, ',');
    String eventDays = getField(line, 2, ',');

    // Extract event hour and minute
    int eventHour = eventTime.substring(0, 2).toInt();
    int eventMinute = eventTime.substring(3, 5).toInt();

    // Debugging: print the event data
    Serial.print("Event Time: ");
    Serial.println(eventTime);
    Serial.print("Current Time: ");
    Serial.println(currentTime);

    // Compare hour and minute directly
    if (currentHour == eventHour && currentMinute == eventMinute && eventDays.indexOf(String(currentDay)) >= 0) {
      // Ensure the event hasn't already been triggered in this minute
      if (lastTriggeredTime != currentTime) {
        // Store the last triggered time
        lastTriggeredTime = currentTime;
        // Trigger the event
        triggerEvent(eventName);
      }
    }
  }

  scheduleFile.close();
}



// Convert time from HH:MM to seconds
unsigned long timeToSeconds(String time) {
  int colonIndex = time.indexOf(':');
  int hour = time.substring(0, colonIndex).toInt();
  int minute = time.substring(colonIndex + 1).toInt();
  return hour * 3600 + minute * 60;  // Convert to seconds
}

// Read a line from the SD card file
void readLine(File &file, char *buffer, size_t length) {
  size_t i = 0;
  while (file.available() && i < length - 1) {
    char c = file.read();
    if (c == '\n') break;
    buffer[i++] = c;
  }
  buffer[i] = '\0'; // Null-terminate the string
}

// Extract a specific field from a comma-separated string
String getField(String data, int index, char delimiter) {
  int start = 0, end = data.indexOf(delimiter);
  for (int i = 0; i < index; i++) {
    start = end + 1;
    end = data.indexOf(delimiter, start);
    if (end == -1) end = data.length();
  }
  return data.substring(start, end);
}

// Trigger an event by turning on the LED
void triggerEvent(String eventName) {
  Serial.print("Triggering event: ");
  Serial.println(eventName);

  digitalWrite(ledPin, HIGH);
  alarmActive = true; // Mark the alarm as active

  // Keep LED on for the RingingTime (in seconds)
  delay(RingingTime * 1000);

  digitalWrite(ledPin, LOW);
  alarmActive = false; // Mark the alarm as inactive
}