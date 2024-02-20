#ifndef AIRPORTMANAGER
#define AIRPORTMANAGER
#include <stdlib.h>
#include "Airport.h"
#include "Plane.h"
#include "Flight.h"

typedef struct{
    Airport** theAirports;
    int numOfAirports;
} AirportManager;

AirportManager* initManager(AirportManager* apm);

int addAirport(AirportManager* apm);

void freeManager(AirportManager* apm);

void printAirports(AirportManager* const apm);

int isAirportCodeInUse(char *code, AirportManager* const apm);

Airport* findAirportByCode(AirportManager* apm, char* code);

#endif // !AIRPORTMANAGER
