#include "Flight.h"
#include <string.h>

int isFlightFromSourceAirport(const Flight* f, char* originCode){
    return strcmp(f->origin, originCode);
}


int isFlightToDestAirport(const Flight* f, char* destCode){
    return strcmp(f->destination, destCode);
}

int isPlaneTypeInFlight(const Flight* f, planeType type){
    return f->plane.type == type;
}
