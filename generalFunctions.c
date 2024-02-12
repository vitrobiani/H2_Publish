#include "generalFunctions.h"
#include <stdlib.h>
#include <string.h>


char* getDynamicStr(char* s){
    int len = strlen(s);
    char* retStr = (char*) malloc(len+1);
    if (s == NULL) {
        retStr = NULL;
    }else {
        strcpy(retStr,s);
    }
    return retStr;
}
