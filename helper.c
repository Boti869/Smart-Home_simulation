#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"include_header/enums.h"

//hour helper
int getHour() {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    int hour = local->tm_hour;
    return hour;
}

//season helper
enum season getSeason() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    int month = tm_info->tm_mon + 1;
    
    if (month == 12 || month <= 2) {
        return WINTER;
    } else if (month <= 5) {
        return SPRING;
    } else if (month <= 8) {
        return SUMMER;
    } else {
        return AUTUMN;
    }
}