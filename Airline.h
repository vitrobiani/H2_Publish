#ifndef AIRLINE
#define AIRLINE
#include <stdio.h>
#include <stdlib.h>
#include "Plane.h"
#include "Flight.h"
#include "generalFunctions.h"
#include "Plane.h"


typedef struct{
    char* name;
    Plane* planes;
    Flight* flights;
} Airline;

Airline* initAirline();

char* initAirlineName();

#endif // !AIRLINE

