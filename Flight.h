#ifndef FILGHT
#define FILGHT
#include <string.h>
#include <stdlib.h>
#include "Plane.h"
#include "Airport.h"
#include "Date.h"

typedef struct{
    Plane* plane;
    char origin[CODE];
    char destination[CODE];
    Date* date;
}Flight;

Flight* initFlight(Plane* plane, Airport* origin, Airport* destination, Date* date);




#endif // !FILGHT
