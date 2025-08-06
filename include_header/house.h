#pragma once
#include "../include_header/enums.h"

typedef struct {
    char name[20];
    
    double temprature; //
    enum motionDetection motionDetection; //
    enum lightLevel lightLevel;//
    enum gasLevel gasLevel; //

    enum fanSpeed fanOn; //
    enum heaterOn heaterOn; //
    enum lightsOn lightOn; //
    enum lightTop lightTop;//
    enum gasAlarmON gasAlarmOn; //

    enum windowOpen windowOpen; //
    enum shades shades;//

} Room;

typedef struct {
    char name[20];
    
    double temperature; //
    enum motionDetection motionDetection; //
    enum lightLevel lightLevel; //
    enum windSpeed windSpeed; //
    enum weather weather; //

    enum lightsOn lightOn; //

} Outdoors;
extern Room house[10];
extern Outdoors outdoor[2];
