#ifndef PLANE
#define PLANE

typedef enum { Passanger, cargo, Milltry }planeType ;
typedef struct {
    int serialNum;
    planeType type;

} Plane;


void initPlane(Plane* p, Plane* planeArr, int sn);

void printPlane(Plane* p);


#endif // !Plane
