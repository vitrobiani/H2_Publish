#include "Airport.h"
#include "generalFunctions.h"
#include <stdlib.h>

Airport *initAirport(Airport *airport) {
    airport = (Airport *)malloc(sizeof(Airport));
    getAirportCode(airport->code);
    getAirportName(airport);
    getAirportCountry(airport);

    return airport;
}

void getAirportCode(char *airportCode) {
    const int expectedLength = 3;
    do {
        printf("Enter airport code - %d UPPER CASE letters:\n ",
               expectedLength);

        char inputBuffer[MAX_LENGTH];
        myGets(inputBuffer, MAX_LENGTH);

        int inputLength = strlen(inputBuffer);
        if (inputLength > 0 && inputBuffer[inputLength - 1] == '\n') {
            inputBuffer[inputLength - 1] = '\0';
        }

        if ((int)strlen(inputBuffer) == expectedLength) {
            bool isValid = true;
            for (int i = 0; i < expectedLength; ++i) {
                if (!isupper((char)inputBuffer[i])) {
                    printf("Need to be upper case letter\n");
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                strcpy(airportCode, inputBuffer);
                return;
            }
        } else {
            printf("Code should be %d letters.\n", expectedLength);
        }
    } while (true);
}

void getAirportName(Airport *port) {
    printf("Enter airport name\n");
    char name[MAX_LENGTH];
    myGets(name, MAX_LENGTH);

    char *rname = makeNameAirporti(name);

    port->name = strdup(rname);
}

char *makeNameAirporti(char *name) {
    char *formatName = malloc(strlen(name));
    strcpy(formatName, name);

    formatName = cleanWhiteSpaceEdges(formatName);
    int wc = wordCount(formatName);
    if (wc == 1) {
        formatName = addUnderlines(formatName);
    } else {
        formatName = makeSpacesAndNameGood(formatName, wc);
    }

    return formatName;
}

char *makeSpacesAndNameGood(char *formatName, int wc) {
    int isEven = wc % 2;
    int sc = 0;
    for (int i = 0; i < (int)strlen(formatName); i++) {
        if (*(formatName + i) == ' ') {
            sc++;
        }
    }
    char *res = malloc(strlen(formatName) + sc);
    for (int i = 0, j = 0; i < (int)strlen(formatName)+1; i++) {
        if (*(formatName + i) == ' ' && *(formatName + i - 1) != ' ') {
            *(res + j) = ' ';
            *(res + j + 1) = ' ';
            j += (isEven) ? 1 : 2;
        } else if (*(formatName + i) != ' ') {
            *(res + j) = ((*(formatName + i - 1) == ' ' || i == 0) &&
                          *(formatName + i) >= 97)
                             ? *(formatName + i) - 32
                             : *(formatName + i);
            j++;
        }
    }
    *(res + strlen(res)+1) = '\0';
    formatName = realloc(res, strlen(res)+1);

    return formatName;
}

void getAirportCountry(Airport *port) {
    printf("Enter Airport country:   ");
    char *name = NULL;
    size_t size = 0;
    getline(&name, &size, stdin);
    port->country = name;
}

void printAirport(Airport const *port) {
    printf("Code: %s, Name: %s, Country: %s \n", port->code, port->name,
           port->country);
}

void freeAirport(Airport *port) {
    free(port->name);
    free(port->country);
    free(port);
}

Airport *initAirportNoCode(Airport *airport) {
    getAirportName(airport);
    getAirportCountry(airport);

    return airport;
}
