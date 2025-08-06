#pragma once 
#include"../include_header/enums.h"
#include"../include_header/house.h"

double getTemperatureOut(double temp);
enum weather getWeather();
enum lightLevel getLightLevel(enum weather currentWeather);
enum windSpeed getwindSpeed(int speed);
enum windSpeed prepSpeed(int weather);
enum motionDetection getMotionOutside(enum weather currentWeather);
enum lightsOn getLightsOut(enum motionDetection m, enum lightLevel current);
