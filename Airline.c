#include "Airline.h"

Airline* initAirline(){
    Airline* airline = malloc(sizeof(Airline));
    char* name = initAirlineName();
    airline->name = name;
    airline->planes = malloc(sizeof(Plane));
    airline->flights = malloc(sizeof(Flight));

    return airline;
}

char* initAirlineName(){
    char* name = NULL;
    size_t size = 0;
    printf("Enter Airline name    ");
    getline(&name, &size , stdin);
    name = getDynamicStr(name);
    return name;
}
