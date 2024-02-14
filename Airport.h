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
    char* country;
} Airport;

Airport* initAirport();

void getAirportCode(char *airportCode);

Airport* initAirportNoCode(Airport* port);

void getAirportName(Airport* port);

char* makeNameAirporti(char* name);

void getAirportCountry(Airport* port);

void printAirport(Airport const *port);

void freeAirport(Airport* port);

char* makeSpacesAndNameGood(char *formatName, int wc);


#endif // !AIRPORT
