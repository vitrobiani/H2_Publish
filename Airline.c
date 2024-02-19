#include "Airline.h"
#include <stdio.h>

Airline *initAirline(Airline *airline) {
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
    char *name = malloc(size * sizeof(char));
    printf(" Enter Airline name    \n");
    do {
        fgets(name, size, stdin);
    } while (name[0] == '\n');
    name = getDynamicStr(name);

    if (strlen(name) > 0 && name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }
    return name;
}

int addPlane(Airline *airline) {
    Plane *p = malloc(sizeof(Plane));
    if (!p)
        return 0;

    initPlane(p, airline->planeArr, airline->planeCount);
    airline->planeCount++;
    airline->planeArr =
        realloc(airline->planeArr, (airline->planeCount) * sizeof(Plane *));
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

Plane* findPlane(Airline* airline){
    int sn;
    printf("Choose a plane from list, type its serial Number\n");
    printPlanesArr(*airline->planeArr, airline->planeCount);   
    
    Plane* p;
    do {
        scanf("%d", &sn);
        p = findPlaneBySn(airline, sn);
    }while (!p);
    return p;
}

Plane* findPlaneBySn(Airline* airline, int sn){
    for (int i = 0; i < airline->planeCount; i++) {
        if ((airline->planeArr[i]->serialNum) == sn)
            return airline->planeArr[i];
    }
    printf("No plane with that serial number! Try again!\n");
    return NULL;
}
