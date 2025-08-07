#include<stdio.h>
#include<stdlib.h>
#include"../include_header/enums.h"
#include"../include_header/house.h"
#include"../include_header/outdoor.h"
#include"../include_header/rooms.h"
#include"../include_header/helper.h"

void updateOutdoors(Outdoors *o) {
    o->temperature = getTemperatureOut(o->temperature);
    o->weather = getWeather();
    o->lightLevel = getLightLevel(o->weather);
    o->windSpeed = prepSpeed(o->weather);
    o->lightOn = getLightsOut(getMotionOutside(o->weather), o->lightLevel);
}

void updateRoom(Room *r, Outdoors *o) {
    printf("======= %s ========\n", r->name);
    printf("Temperature: %.1f°C\n",r->temprature);

    r->fanOn = getFanSpeed(&r->temprature);
    r->heaterOn = getHeater(r->temprature);
    r->gasAlarmOn = getGasAlarm(getGasLevel(), r - house);
    r->windowOpen = getWindowOpen(r->temprature, o->weather);
    r->shades = getShades(o->temperature, getSeason(), o->weather);
    r->lightTop = getLightTop(o->lightLevel);
    r->lightOn = getLightOn(getMotionInside(r->lightTop), o->lightLevel);
}