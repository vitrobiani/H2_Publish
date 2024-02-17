#include "Airline.h"
#include "Flight.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Airline *initAirline(Airline *airline) {
    airline = malloc(sizeof(Airline));
    char *name = initAirlineName();
    airline->name = name;
    airline->planeArr = NULL;
    airline->flights = NULL;
    airline->planeCount = 0;
    airline->flightCount = 0;

    return airline;
}

char *initAirlineName() {
    size_t size = 100;
    char *name = malloc(size*sizeof(char));
    printf(" Enter Airline name    \n");
    do {
        fgets(name, size, stdin);
    }while (name[0] == '\n');
    name = getDynamicStr(name);

    if (strlen(name) > 0 && name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    return name;
}

int addPlane(Airline *airline) {
    Plane *p = malloc(sizeof(Plane));
    if (!p) return 0;

    initPlane(p, airline->planeArr, airline->planeCount);
    airline->planeCount++;
    airline->planeArr = realloc(airline->planeArr, (airline->planeCount) * sizeof(Plane*));
    airline->planeArr[airline->planeCount - 1] = p;

    return 1;
}

void printPlanesArr(Plane *planeArr, int s) {
    for (int i = 0; i < s; i++) {
        printPlane(&planeArr[i]);
    }
}

void freeCompany(Airline *airline) {
    free(airline->name);
    free(airline->planeArr);
    free(airline->flights);
}
