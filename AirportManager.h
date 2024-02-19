#ifndef AIRPORTMANAGER
#define AIRPORTMANAGER
#include <stdlib.h>
#include "Airport.h"
#include "Plane.h"
#include "Flight.h"
#include "Airline.h"

typedef struct{
    Airport** theAirports;
    int numOfAirports;
} AirportManager;

AirportManager* initManager(AirportManager* apm);

int addAirport(AirportManager* apm);

void freeManager(AirportManager* apm);

void printAirports(AirportManager* const apm);

int isAirportCodeInUse(char *code, AirportManager* const apm);

int addFlight(Airline* airline, AirportManager* apm);

int getAirportsForFlight(Flight* f, AirportManager* apm);

#endif // !AIRPORTMANAGER
