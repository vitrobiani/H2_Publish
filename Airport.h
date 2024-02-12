#ifndef AIRPORT
#define AIRPORT
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define CODE 3

typedef struct{
    char code[CODE];
    char* name;
} Airport;

Airport* initAirport();

void getAirportCode(char *airportCode);

Airport* initAirportNoCode(Airport* port);

void getAirportName(Airport* port);

void printAirport(Airport* port);

void freeAirport(Airport* port);


#endif // !AIRPORT
