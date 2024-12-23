#include "Scheduler.h"

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

    debug("Updating scheduler...");
    debug("Current time: " + currentTime);

    if (!alarmActive) {
        checkSchedule(currentTime, currentDay);
    }
}

void Scheduler::debug(const String& message) {
    Serial.println(message);
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

        debug("Read line: " + line);

        String eventTime = getField(line, 0, ',');
        String eventName = getField(line, 1, ',');
        String eventDays = getField(line, 2, ',');

        debug("Event time: " + eventTime + ", Event name: " + eventName + ", Event days: " + eventDays);

        if (currentTime == eventTime && eventDays.indexOf(String(currentDay)) >= 0 && lastTriggeredTime != currentTime) {
            lastTriggeredTime = currentTime;
            triggerEvent(eventName);
        }
    }
    scheduleFile.close();
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

void Scheduler::triggerEvent(String eventName) {
    debug("Triggering event: " + eventName);

    digitalWrite(ledPin, HIGH);
    alarmActive = true;
    delay(ringingTime * 1000);
    digitalWrite(ledPin, LOW);
    alarmActive = false;

    debug("Event complete: " + eventName);
}
