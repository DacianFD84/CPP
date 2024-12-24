#include "Scheduler.h"

// Debugging toggle - Enable or disable debug output
#define ENABLE_DEBUG true

Scheduler::Scheduler(int chipSelectPin, int ledPin, const String& scheduleFileName, unsigned long ringingTime)
    : chipSelect(chipSelectPin), ledPin(ledPin), scheduleFileName(scheduleFileName), ringingTime(ringingTime), alarmActive(false), lastTriggeredTime("") {}


void Scheduler::init() {

    debug("Initializing RTC...");
    if (!rtc.begin()) {
        debug("RTC not found!");
        while (1);
    }

    debug("Initializing SD card...");
    if (!SD.begin(chipSelect)) {
        debug("SD card initialization failed!");
        return;
    }

    debug("Setting up LED pin...");
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    debug("Scheduler initialized successfully.");
}



void Scheduler::update() {
    DateTime now = rtc.now();
    String currentTime = formatWithLeadingZero(now.hour()) + ":" + formatWithLeadingZero(now.minute());
    int currentDay = now.dayOfTheWeek();

    log("Current Time", currentTime);
    log("Current Day", String(currentDay));

    if (!alarmActive) {
        checkSchedule(currentTime, currentDay);
    }
}



void Scheduler::debug(const String& message) {
    if (ENABLE_DEBUG) {
        Serial.println(message);
    }
}



void Scheduler::log(const String& label, const String& value) {
    if (ENABLE_DEBUG) {
        Serial.print(label + ": ");
        Serial.println(value);
    }
}


String Scheduler::formatWithLeadingZero(int value) {
    return value < 10 ? "0" + String(value) : String(value);
}


void Scheduler::checkSchedule(String currentTime, int currentDay) {
    debug("Checking schedule...");

    File scheduleFile = SD.open(scheduleFileName);

    if (!scheduleFile) {
        debug("Error opening schedule file!");
        return;
    }

    char lineBuffer[128];

    while (scheduleFile.available()) {

        readLine(scheduleFile, lineBuffer, sizeof(lineBuffer));
        String line = String(lineBuffer);

        log("Read Line", line);

        String eventTime = getField(line, 0, ',');
        String eventName = getField(line, 1, ',');
        String eventDays = line.substring(line.indexOf(',', line.indexOf(',') + 1) + 1); // Extract everything after the second comma

        log("Event Time", eventTime);
        log("Event Name", eventName);
        log("Event Days", eventDays);

        if (currentTime == eventTime && isDayInEventDays(currentDay, eventDays) && lastTriggeredTime != currentTime) {
            lastTriggeredTime = currentTime;
            debug("Triggering event...");
            
            triggerEvent(eventName); 
            
        }
    }
    scheduleFile.close();
}



bool Scheduler::isDayInEventDays(int currentDay, String eventDays) {
    int start = 0;
    while (true) {
        int commaIndex = eventDays.indexOf(',', start);
        String day = eventDays.substring(start, commaIndex);

        if (day.toInt() == currentDay) {
            return true; // Match found
        }

        if (commaIndex == -1) {
            break; // End of string
        }
        start = commaIndex + 1; // Move to the next segment
    }
    return false; // No match found
}


unsigned long Scheduler::timeToSeconds(String time) {
    int colonIndex = time.indexOf(':');
    int hour = time.substring(0, colonIndex).toInt();
    int minute = time.substring(colonIndex + 1).toInt();
    return hour * 3600 + minute * 60;
}


void Scheduler::readLine(File &file, char *buffer, size_t length) {
    size_t i = 0;
    while (file.available() && i < length - 1) {
        char c = file.read();
        if (c == '\n') break;
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}


String Scheduler::getField(String data, int index, char delimiter) {
    int start = 0, end = data.indexOf(delimiter);
    for (int i = 0; i < index; i++) {
        start = end + 1;
        end = data.indexOf(delimiter, start);
        if (end == -1) end = data.length();
    }
    return data.substring(start, end);
}

// Această funcție declanșează un eveniment specificat pentru o anumită perioadă de timp.

void Scheduler::triggerEvent(String eventName) {
    debug("Triggering event: " + eventName);

    digitalWrite(ledPin, HIGH);
    alarmActive = true;
    delay(ringingTime * 1000);
    digitalWrite(ledPin, LOW);
    alarmActive = false;

    debug("Event complete: " + eventName);
}
