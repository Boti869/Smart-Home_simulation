#pragma once 
#include"../include_header/enums.h"
#include"../include_header/house.h"
#include"../include_header/outdoor.h"

double getFanSpeed(double *temperature);
enum heaterOn getHeater(double temperature);
enum windowOpen getWindowOpen(double temp, enum weather currentWeather);
enum gasLevel getGasLevel();
int highGas(Room house[], int size, int triggeredRoom);
enum gasAlarmON getGasAlarm(int gasLevel, int roomIndex);
enum shades getShades(double temp, enum season season, enum weather weather);
enum lightTop getLightTop(enum lightLevel c);
enum motionDetection getMotionInside(enum lightTop light);
enum lightsOn getLightOn(enum motionDetection m, enum lightLevel ll);