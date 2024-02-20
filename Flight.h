#ifndef FILGHT
#define FILGHT
#include <string.h>
#include <stdlib.h>
#include "Plane.h"
#include "Airport.h"
#include "Date.h"

typedef struct{
    char origin[CODE+1];
    char destination[CODE+1];
    Plane plane;
    Date date;
}Flight;

Flight* initFlight(Plane* plane, Airport* origin, Airport* destination, Date* date);

int isFlightFromSourceAirport(const Flight* f, char* originCode);

int isFlightToDestAirport(const Flight* f, char* destCode);

int isPlaneTypeInFlight(const Flight* f, planeType type);

#endif // !FILGHT
