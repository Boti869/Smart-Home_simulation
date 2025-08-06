/*COMPILE WITH THE FOLLOWING COMMAND:
gcc main.c rooms.c outdoors.c setup.c updates.c helper.c house.c -o main.exe -Wall -g */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"include_header/enums.h"
#include"include_header/house.h"
#include"include_header/outdoor.h"
#include"include_header/rooms.h"
#include"include_header/setup.h"
#include"include_header/helper.h"
#include"include_header/updates.h"

int main() {
    srand(time(NULL));

    switch(getSeason()) {
        case WINTER:
            printf("\nWinter settings activated!\n\n");
            setup(20.0, 55, -5.0, 26.0);
            break;

        case SPRING:
            printf("\nSpring settings activated!\n\n");
            setup(22.0, 40, 15.0, 25.0);
            break;
        
        case SUMMER:
            printf("\nSummer settings activated!\n\n"); 
            setup(24.1, 60, 23.0, 27.7);
            break;
        
        case AUTUMN:
            printf("\nAutumn settings activated\n\n"); 
            setup(21.0, 50, 15.0, 25.6);
            break;
    }   
    
    return 0;
}