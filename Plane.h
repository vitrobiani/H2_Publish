#ifndef PLANE
#define PLANE
#include <stdio.h>
#include <stdlib.h>

typedef enum { Commercial, Cargo, Military, noOfType}planeType;
static const char* planeTypeStr[noOfType] __attribute__((unused)) = {"Commercial", "Cargo", "Military" };

typedef struct {
    planeType type;
    int serialNum;
} Plane;


void initPlane(Plane* p, Plane* planeArr, int s);

int getPlaneSN(Plane* planeArr, int s);

int isSerialNumUnique(Plane* planeArr, int sn, int s);
 
planeType getPlaneType();

void printPlane(Plane* const p);

char* PlaneTypeStr();

#endif // !Plane
