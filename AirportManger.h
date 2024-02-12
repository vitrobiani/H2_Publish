#ifndef AIRPORTMANAGER
#define AIRPORTMANAGER
#include "Airport.h"
#include "plane.h"
#include "Flight.h"

typedef struct{
    Airport* theAirports;
    int numOfAirports;
} AirportManager;

void initManager();




#endif // !AIRPORTMANAGER
