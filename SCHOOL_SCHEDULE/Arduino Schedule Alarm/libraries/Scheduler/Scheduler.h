#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Wire.h>
#include <SD.h>
#include <RTClib.h>

class Scheduler {
public:
    Scheduler(int chipSelectPin, int ledPin, const String& scheduleFileName, unsigned long ringingTime);

    void init();
    void update();

private:
    int chipSelect;
    int ledPin;
    String scheduleFileName;
    unsigned long ringingTime;
    bool alarmActive;
    String lastTriggeredTime;
    RTC_DS3231 rtc;

    void debug(const String& message);
    String formatWithLeadingZero(int value);
    void checkSchedule(String currentTime, int currentDay);
    unsigned long timeToSeconds(String time);
    void readLine(File &file, char *buffer, size_t length);
    String getField(String data, int index, char delimiter);
    void triggerEvent(String eventName);
};

#endif
