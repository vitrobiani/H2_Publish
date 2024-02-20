#include "Airline.h"
#include "Plane.h"
#include "generalFunctions.h"
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
    char *name = NULL; 
    printf(" Enter Airline name    \n");
    myGets(name, MAX_LENGTH);
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
    
    Plane* p = NULL;
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

void printCompany(Airline* const airline){
    printf(" -------- Has %d plane", airline->planeCount);    
}


int addFlight(Airline *airline, AirportManager *apm) {
    Flight *f = NULL;
    if (apm->numOfAirports <= 1) {
        printf("There are not enough airport to add flight");
        return 0;
    } else if (airline->planeCount == 0) {
        printf("There is no plane in company");
        return 0;
    } else {
        f->plane = *findPlane(airline);
        if (getAirportsForFlight(f, apm) && getCorrectDate(&(f->date))) return 0;
        airline->flightCount++;
    }
    return 1;
}

int getAirportsForFlight(Flight *f, AirportManager *apm) {
    printAirports(apm);
    int inUse, rot = 0;
    char *code = NULL;
    do {
        printf("Enter code of %s airport:     ",(rot) ? ("destination") : ("origin"));
        myGets(code, MAX_LENGTH);
        inUse = isAirportCodeInUse(code, apm);
        if (!inUse) {
            printf("No airport with this code - try again\n");
        } else if (inUse && !rot) {
            strcpy(f->origin, code);
            rot++;
        } else if (inUse && rot) {
            if (strcmp(code, f->origin)) {
                printf("Same origin and destination airport\n");
                inUse = 0;
            }else{
                strcpy(f->destination, code);
            }
        } else {
            return 0;
        }
    } while (!inUse && !rot);
    return 1;
}

void doPrintFlightsWithPlaneType(Airline* const airline){
    planeType type = getPlaneType();
    for (int i = 0; i < airline->planeCount; i++) {
        if (airline->planeArr[i]->type == type) {
            printPlane(airline->planeArr[i]);
        }
    }
}
