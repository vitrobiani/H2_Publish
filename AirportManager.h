#ifndef AIRPORTMANAGER
#define AIRPORTMANAGER
#include "Airport.h"
#include "Plane.h"
#include "Flight.h"

typedef struct{
    Airport** theAirports;
    int numOfAirports;
} AirportManager;

AirportManager* initManager();

int addAirportToManager(AirportManager* apm, Airport *port);



#endif // !AIRPORTMANAGER
