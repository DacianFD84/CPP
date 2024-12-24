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
    void updateDate();  // Declaration of the new updateDate function
    

private:
    int chipSelect;
    int ledPin;
    String scheduleFileName;
    unsigned long ringingTime;
    bool alarmActive;
    String lastTriggeredTime;
    RTC_DS3231 rtc;
    

    void debug(const String& message);  // Core debug handler
    void log(const String& label, const String& value); // Debug log for key-value pairs
    String formatWithLeadingZero(int value);
    void checkSchedule(String currentTime, int currentDay);
    unsigned long timeToSeconds(String time);
    void readLine(File &file, char *buffer, size_t length);
    String getField(String data, int index, char delimiter);

    void triggerEvent(String eventName);  // Handles event triggering
    
    bool isDayInEventDays(int currentDay, String eventDays); // Function to check if the current day matches the event days
    
};

#endif
