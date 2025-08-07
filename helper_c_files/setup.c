#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"../include_header/enums.h"
#include"../include_header/house.h"
#include"../include_header/outdoor.h"
#include"../include_header/rooms.h"
#include"../include_header/updates.h"

void start() {
    updateOutdoors(&outdoor[0]);
    printf("\n");
    Sleep(1000);
}

void end(int i) {
    updateRoom(&house[i], &outdoor[0]);
    printf("\n\n");
    Sleep(2000);
}

//setup
void setup(double base, int add, double limit, double max) { 
    start();
    for(int i = 0; i< 10; i++){
        house[i].temprature = base + (rand()% add) /10.0;
        if(outdoor[0].temperature <= limit) {
            house[i].temprature -= 0.6;
            if(house[i].temprature >= max) house[i].temprature = max;
        }
        
        end(i);  
    }
}