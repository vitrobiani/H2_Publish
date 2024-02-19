#include "AirportManager.h"
#include "Airport.h"
#include "Date.h"
#include "Flight.h"
#include <stdio.h>
#include <string.h>

AirportManager *initManager(AirportManager *apm) {
    apm->theAirports = NULL;
    apm->numOfAirports = 0;

    return apm;
}

int addAirport(AirportManager *apm) {
    Airport *port = (Airport *)malloc(sizeof(Airport));
    int isCodeInUse;
    do {
        getAirportCode(port->code);
        isCodeInUse = isAirportCodeInUse(port->code, apm);
        if (isCodeInUse)
            printf("This code already in use - enter a different code\n");
    } while (isCodeInUse);
    port = initAirportNoCode(port);
    apm->numOfAirports++;
    apm->theAirports =
        realloc(apm->theAirports, (apm->numOfAirports) * sizeof(Airport *));
    apm->theAirports[apm->numOfAirports - 1] = port;
    apm->theAirports =
        realloc(apm->theAirports, (apm->numOfAirports) * sizeof(Airport *));

    if (!(port))
        return 0;
    return 1;
}

int isAirportCodeInUse(char *code, AirportManager *const apm) {
    for (int i = 0; i < apm->numOfAirports; i++) {
        if (strcmp(apm->theAirports[i]->code, code) == 0) {
            return 1;
        }
    }
    return 0;
}

void printAirports(AirportManager *const apm) {
    for (int i = 0; i < apm->numOfAirports; i++) {
        printAirport(apm->theAirports[i]);
    }
}

void freeManager(AirportManager *apm) {
    for (int i = 0; i < apm->numOfAirports; i++) {
        freeAirport(apm->theAirports[i]);
    }
    free(apm->theAirports);
}

int addFlight(Airline *airline, AirportManager *apm) {
    Flight *f = NULL;
    if (apm->numOfAirports <= 1) {
        printf("There are not enough airport to add flight");
        return 0;
    } else if (airline->flightCount == 0) {
        printf("There is no plane in company");
        return 0;
    } else {
        f->plane = findPlane(airline);
        if (getAirportsForFlight(f, apm) && getCorrectDate(f->date)) return 0;
    }
    return 1;
}

int getAirportsForFlight(Flight *f, AirportManager *apm) {
    printAirports(apm);
    int inUse, rot = 0;
    char *code = NULL;
    do {
        printf("Enter code of %s airport:     ",
               (rot) ? ("destination") : ("origin"));
        size_t s = 0;
        getline(&code, &s, stdin);
        inUse = isAirportCodeInUse(code, apm);
        if (!inUse) {
            printf("No airport with this code - try again\n");
        } else if (inUse && !rot) {
            strcpy(f->origin, code);
            rot++;
        } else if (inUse && rot) {
            if (!strcmp(code, f->origin)) {
                printf("Same origin and destination airport\n");
            }
            strcpy(f->destination, code);
        } else {
            return 0;
        }
    } while (!inUse && rot);
    free(code);
    return 1;
}
