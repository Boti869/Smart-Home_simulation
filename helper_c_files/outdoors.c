#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include<windows.h>
#include"../include_header/enums.h"
#include"../include_header/house.h"
#include"../include_header/outdoor.h"
#include"../include_header/rooms.h"
#include"../include_header/helper.h"


//temperature
double getTemperatureOut(double temp) {
    printf("What is the temperature outside (in Celsius)? ");
    scanf("%lf", &temp);
    
    return temp;
}

//weather
enum weather getWeather() {
    int weather;
    printf("What is the weather? (0: Sunny, 1: Cloudy, 2: Full cloud cover, 3: Rainy, 4: Windy, 5: Snowy): ");
    scanf("%d", &weather);
    while(weather < 0 || weather >= 6) {
        printf("Invalid input. Please enter a number between 0 and 5: ");
        scanf("%d", &weather);
    }
    return (enum weather) weather;
}

//made-up lighlevel
enum lightLevel getLightLevel(enum weather currentWeather) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    int hour = local->tm_hour;
    int minute = local->tm_min;
    double real_hour = hour + (minute / 60.0);
    
    enum lightLevel baseLevel = DARK;
    switch (getSeason()) {
    case WINTER:
        if (real_hour < 6.5) baseLevel = DARK;
        else if (real_hour < 7.5) baseLevel = DiM;
        else if (real_hour < 14) baseLevel = BRIGHT;
        else if (real_hour < 16) baseLevel = NORMAL;
        else if (real_hour < 16.5) baseLevel = DiM;
        else baseLevel = DARK;
        break;
    
    case SPRING:
        if (real_hour < 5.3) baseLevel = DARK;
        else if (real_hour < 5.8) baseLevel = DiM;
        else if (real_hour < 18.5) baseLevel = BRIGHT;
        else if (real_hour < 19.5) baseLevel = NORMAL;
        else if (real_hour < 20.25) baseLevel = DiM;
        else baseLevel = DARK;
        break;

    case SUMMER:
        if (real_hour < 4.25) baseLevel = DARK;
        else if (real_hour < 5) baseLevel = DiM;
        else if (real_hour < 19.5) baseLevel = BRIGHT;
        else if (real_hour < 20.8) baseLevel = NORMAL;
        else if (real_hour < 21.5) baseLevel = DiM;
        else baseLevel = DARK;
        break;
    
    case AUTUMN:
        if (real_hour < 6.8) baseLevel = DARK;
        else if (real_hour < 7.3) baseLevel = DiM;
        else if (real_hour < 17) baseLevel = BRIGHT;
        else if (real_hour < 17.8) baseLevel = NORMAL;
        else if (real_hour < 18.4) baseLevel = DiM;
        else baseLevel = DARK;
        break;
    }

    switch(currentWeather) {
        case CLOUDY:        if(baseLevel > DiM) baseLevel --; break;
        case FULL_CLOUD:    if(baseLevel > DARK) baseLevel -= 2; break;
        case RAINY:         if(baseLevel > DARK) baseLevel -= 2; break;
        case WINDY:         break;
        case SNOWY:         if(baseLevel < VERY_BRIGHT) baseLevel ++; break;
        default: break;
    }

    if(baseLevel < DARK) baseLevel = DARK;
    if(baseLevel > VERY_BRIGHT) baseLevel = VERY_BRIGHT;
    return baseLevel;

}

//random wind speed
enum windSpeed getwindSpeed(int speed) {
    if (speed <= 1) return CALM;
    else if (speed <= 2) return BREEZY;
    else if (speed <= 3) return WIND;
    else if (speed <= 4) return STORMY;
    else return HURRICANE;

}

enum windSpeed prepSpeed(int weather) {
    int windSpeed;
    int prob = rand() % 100;
    
    
    if(weather == SUNNY || weather == CLOUDY) {            
        if(prob < 70) windSpeed = 1;
        else windSpeed = 2;
    }            
    
    else if (weather == FULL_CLOUD) {
        if(prob < 40) windSpeed = 1;
        else if(prob < 70) windSpeed = 2;
        else windSpeed = 3;
       }
    else if (weather == RAINY) {
        if(prob < 30) windSpeed = 2;
        else if(prob < 70) windSpeed = 3;
        else if(prob < 99) windSpeed = 4;
        else {windSpeed = 5;}

  
        }
    else if (weather == WINDY) {
        if (prob < 55) windSpeed = 3;
        else if (prob < 94) windSpeed = 4;
        else windSpeed = 5;               
    }
    else if (weather == SNOWY) {
        if (prob < 50) windSpeed = 1;
        else if (prob < 80) windSpeed = 2;
        else if (prob < 95) windSpeed = 3;
        else windSpeed = 4;                   
        // Hurricanes in snow are nearly impossible, so 5 is a skip
}
    printf("Wind speed: %d\n", windSpeed);
    return getwindSpeed(windSpeed);

}

//Outdoors motion and lights
enum motionDetection getMotionOutside(enum weather currentWeather) {
    int motion = rand() % 10 > 6 ? MOTION_DETECTED : NO_MOTION;

    switch(motion) {
        case NO_MOTION: 
        printf("No motion detected.\n"
                "Lights are off.\n");
        return NO_MOTION;
        

        case MOTION_DETECTED: 
            return MOTION_DETECTED;
    }
    return 0;
}

enum lightsOn getLightsOut(enum motionDetection m, enum lightLevel current) {
        switch(m) {
            case NO_MOTION:
            return OFF_LIGHT;

        case MOTION_DETECTED: 
            if(current == DARK) {
            printf("lights are on bright\n"); 
            return ON_BRIGHT;
            }
            else if(current == DiM) {
            printf("lights are on normal\n");    
            return ON_NORMAL;     
            }
            else
            printf("Motion detected, but no need for the lights!\n");
        }
        return 0;
}