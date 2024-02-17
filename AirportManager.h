#ifndef AIRPORTMANAGER
#define AIRPORTMANAGER
#include "Airport.h"
#include "Plane.h"
#include "Flight.h"
#include <stdlib.h>

typedef struct{
    Airport** theAirports;
    int numOfAirports;
} AirportManager;

AirportManager* initManager(AirportManager* apm);

int addAirport(AirportManager* apm);

void freeManager(AirportManager* apm);

void printAirports(AirportManager* const apm);

int isAirportCodeInUse(char *code, AirportManager* const apm);

#endif // !AIRPORTMANAGER
