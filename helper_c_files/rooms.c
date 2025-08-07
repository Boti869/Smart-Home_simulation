#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include<windows.h>
#include"include_header/enums.h"
#include"include_header/house.h"
#include"include_header/outdoor.h"
#include"include_header/rooms.h"
#include"include_header/helper.h"

//fan speed
double getFanSpeed(double *temperature) {
    if (*temperature <= 26) {
    printf("No need for the fan.\n");
    return OFF;
    }
    else if (*temperature <= 27.5){
        printf("Fan is on at a low speed.\n");
        *temperature-= 0.4;
        printf("Now the temperature is: %.1f\n", *temperature);
        return LOW;
    }
    else if (*temperature <= 28.5) {
        printf("Fan is on at a medium speed.\n");
       *temperature-= 0.8;
        printf("Now the temperature is: %.1f\n", *temperature);
        return MEDIUM;
    }
    else {
        printf("Fan is on at a high speed.\n");
        *temperature-= 1.8;
        printf("Now the temperature is: %.1f\n", *temperature);
        return HIGH;
    }

}

//heating
enum heaterOn getHeater(double temperature) {
    if (temperature <= 24.0) {
        printf("Heater is on....\n");
        for (; temperature == 24.0; temperature++) {
            printf("Temperature: %.1f\n", temperature);
            Sleep(1000);
        }
        return OFF_HEATER;
    }
    else {
    printf("No need for the heater.\n");
    return OFF_HEATER; 
    }
}

//window state
enum windowOpen getWindowOpen(double temp, enum weather currentWeather) {
    if (temp <= 24.0 || (currentWeather != SUNNY && currentWeather != CLOUDY) || temp >= 32.0) {
        printf("Window is closed\n");
        return CLOSED;
    }
    if (temp <= 27.0 && currentWeather != RAINY){
        printf("Window is tilted\n");
        return OPEN; 
    }
    else if (temp <= 32.0 && currentWeather != RAINY){
        printf("Window is open\n");
        return TILTED; 
    }
    else {
        printf("Window is tilted\n");
        return TILTED;
    }
}

//random gas level with alarm
enum gasLevel getGasLevel() {
    
    int prob = rand() % 101; 
    
    if (prob <= 80) {
    return LOW_;
    }else if (prob <= 95){ 
    return MEDIUM_;
}   else if (prob <= 97) {
    return HIGH_;
    }
    else {
    return EXTREME_;
    }
}

int highGas(Room house[], int size, int triggeredRoom) {
    printf("!!! HIGH GAS ALERT in %s !!!\n", house[triggeredRoom].name);
    printf("Opening windows, turning on fan, and shutting off heater in the house.\n");

    for (int i = 0; i < size; i++) {
        house[i].windowOpen = OPEN;
        house[i].fanOn = HIGH;
        house[i].heaterOn = OFF_HEATER;
        house[i].lightOn = ON_BRIGHT;
        printf("%s: Fan: HIGH, Heater: OFF, Windows: OPEN, Lights: ON\n", house[i].name);
    }

    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    
    char *firemen = "Fire department was notified";
    char *firemenNo = "Fire department wasn't notified";
    int alert = rand() % 10 > 7 ? 0 : 1;
    if(alert == 1) {
        printf("%s\n",firemen);
    }
    else {
        printf("%s\n",firemenNo);
    }

    char filename[50];
    strftime(filename, sizeof(filename), "Gas_logs/GAS_ALERT_%Y-%m-%d_%H-%M-%S.txt", local);
    FILE *gas = fopen(filename, "w");

    if (gas == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    fprintf(gas,
        "Gas alert in %s\nSafety protocol initiated\n%s\n"
        "Possible leak detected, call a professional ASAP\n",
        house[triggeredRoom].name,
        alert ? firemen : firemenNo);

    fclose(gas);
    exit(0);
}

enum gasAlarmON getGasAlarm(int gasLevel, int roomIndex) {
    if (gasLevel == LOW_) {
        printf("Gas level is low, all good.\n");
        return OFF_ALARM;
    } 
    else if (gasLevel == MEDIUM_) {
        printf("Gas level is medium, be aware.\n");
        return OFF_ALARM;
    } 
    else if (gasLevel == HIGH_ || gasLevel == EXTREME_) {
        if (gasLevel == HIGH_) printf("Gas level is high!\nSafety activated.\n");
        else printf("Gas level is extreme!\nSafety activated.\n");
        highGas(house, 10, roomIndex);
        return ON_ALARM;
    }
    return 0;
}

//shades 
enum shades getShades(double temp, enum season season, enum weather weather) {
    int LL = getLightLevel(weather);

    if(LL == DARK || LL == DiM) {
        printf("Shades are down.\n");
        return DOWN;
    }
    else if(season == SUMMER && (LL == BRIGHT || temp >= 27.0)) {
        printf("Shades are down, slits open.\n");
        return HALF;
    } 
    else {
        printf("Shades are up.\n");
        return UP;
    }
}

//celling lights
enum lightTop getLightTop(enum lightLevel c) {
    int light = rand() % 10 > 4 ? OOFF : ON; 

    if(light == ON && (c == BRIGHT || c == VERY_BRIGHT)) {
        printf("Lights are off.\n");
        return OOFF;
    }
    else if(c == NORMAL) {
        light = rand() % 10 > 6 ? ON : OOFF;
        switch(light)   {
            case ON:
            printf("Lights are on.\n");
            return ON;
            case OOFF:
            printf("Lights are off.\n");
            return OOFF;
        }
        return light;
    }
    return 0;
}

//floor/foot lights
enum motionDetection getMotionInside(enum lightTop light) {
    int hour = getHour();
    int motion = rand() % 10 > 7 ? MOTION_DETECTED : NO_MOTION;

    switch(motion) {
        case NO_MOTION: 
        printf("No motion detected.\n");
        return NO_MOTION;
        
        case MOTION_DETECTED: 
            if (hour <= 6 && hour >= 19 && light == OOFF) {
                printf("Motion detected!\n");

                return MOTION_DETECTED;
            }
            else {
                printf("No motion detected.\n");
                return NO_MOTION;
            }
    }
    return 0;
}

enum lightsOn getLightOn(enum motionDetection m, enum lightLevel ll) {
    switch(m) {
        case NO_MOTION: 
        printf("Lights are off.\n");
        return OFF_LIGHT;
        
        case MOTION_DETECTED: 
                switch(ll) {
                    case DARK:
                    case DiM: 
                        printf("Floor lights are on dim\n");
                        return ON_DIM;
                        break;
                    case NORMAL: 
                        printf("Floor lights are on normal\n"); 
                        return ON_NORMAL;
                        break;
                    case BRIGHT:
                    case VERY_BRIGHT: 
                        printf("No need for the floor lights.\n");
                        return OFF_LIGHT;
                        break;
                }        
    }
    return 0;
}