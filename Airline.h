#ifndef AIRLINE
#define AIRLINE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Plane.h"
#include "Flight.h"
#include "generalFunctions.h"
#include "Plane.h"


typedef struct{
    char* name;
    Plane** planeArr;
    Flight** flights;
    int planeCount;
    int flightCount;
} Airline;

Airline* initAirline(Airline* airline);

char* initAirlineName();

int addPlane(Airline* airline);

void printPlanesArr(Plane* planes, int planeCount);

void printAirline(Airline* const airline);

void freeCompany(Airline* airline);

#endif // !AIRLINE

