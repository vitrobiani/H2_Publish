#include "Plane.h"

void initPlane(Plane *p, Plane *planeArr, int s){
    p->serialNum = getPlaneSN(planeArr, s);
    p->type = getPlaneType();
}

int getPlaneSN(Plane* planeArr, int s){
    int sn, i = 0;
    do{
    printf("Enter plane serial number - between %d and %d\n", 1, 0x270f);
    scanf("%d", &sn);
    if (sn > 0 && sn <= 0x270f)
        i = isSerialNumUnique(planeArr, sn, s);
    }while (i == 0);
    return sn;
}

int isSerialNumUnique(Plane* planeArr, int sn , int s){
    for (int i = 0; i < s; i++){
        if (planeArr[i].serialNum == sn)
            return 0;
    }
    return 1;
}

planeType getPlaneType(){
    int type;
    for (int i = 0; i < 3; i++) {
        printf("%d for %s\n", i, (i == 0) ? "Passanger" : (i == 1) ? "cargo" : "Milltry");
    }
    scanf("%d", &type);
    return type;
}

void printPlane(Plane* const p){
    printf("Serial number: %d, type: %s", p->serialNum, planeTypeStr[p->type]);
}
