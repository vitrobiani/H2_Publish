#include "AirportManager.h"
#include "Airport.h"
#include <stdlib.h>

AirportManager* initManager(){
    AirportManager* apm = malloc(sizeof(AirportManager));
    apm->theAirports = malloc(sizeof(Airport*));
    apm->numOfAirports = 0;

    return apm;
}

int addAirportToManager(AirportManager* apm, Airport *port){
    *(apm->theAirports + (apm->numOfAirports)*sizeof(Airport)) = port;
    apm->theAirports = realloc(apm->theAirports, (apm->numOfAirports)*sizeof(Airport));

    if (!(apm->numOfAirports)) return 0;
    return 1;
}
