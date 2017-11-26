#include <stdio.h>

#include "pe12-3a.h"

void set_mode(int m, int *mode) {
    if (m > 1) 
        printf("Invalid mode specified. Mode %s used\n", 
                *mode == 0 ? "0 (metric)" : "1 (US)");
    else
        *mode = m;
}

void get_info(int mode, int *distance, double *fuel) {
    if (mode == 0) {
        printf("Enter distance traveled in kilometers: ");
        scanf("%d", distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", fuel);
    } else {
        printf("Enter distance traveled in miles: ");
        scanf("%d", distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", fuel);
    }
}

void show_info(int mode, int distance, double fuel) {
    if (mode == 0)
        printf("Fuel comsumption is %.1f liter per 100 km\n",
                fuel * 100 / distance);
    else
        printf("Fuel comsumption is %.1f miles per gallon.\n",
                distance / fuel);
}
