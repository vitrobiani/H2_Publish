#include "Airport.h"
#include "Airline.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

Airport *initAirport(Airport *airport) {
    airport = (Airport *)malloc(sizeof(Airport));
    getAirportCode(airport->code);
    getAirportName(airport);
    getAirportCountry(airport);

    return airport;
}

void getAirportCode(char *airportCode) {
    const int expectedLength = 3;
    const int maxLength = 0xff;

    while (true) {
        printf("Enter airport code - %d UPPER CASE letters:\n ", expectedLength);

        char inputBuffer[maxLength];
        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        // Remove the newline character from the input buffer
        size_t inputLength = strlen(inputBuffer);
        if (inputLength > 0 && inputBuffer[inputLength - 1] == '\n') {
            inputBuffer[inputLength - 1] = '\0';
        }

        // Validate the length of the input
        if (strlen(inputBuffer) == expectedLength) {
            // Validate that all characters are uppercase letters
            bool isValid = true;
            for (int i = 0; i < expectedLength; ++i) {
                if (!isupper((unsigned char)inputBuffer[i])) {
                    puts("Need to be upper case letter");
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                // Copy the valid input to the output parameter
                strcpy(airportCode, inputBuffer);
                return;
            }
        } else {
            printf("Code should be %d letters.\n", expectedLength);
        }
    }
}

void getAirportName(Airport *port) {
    printf("Enter airport name \n");
    char *name = NULL;
    size_t size = 0;
    getline(&name, &size, stdin);

    char* rname = makeNameAirporti(name);

    port->name = strdup(rname);
}

char *makeNameAirporti(char *name) {
    char *formatName = malloc(strlen(name));
    strcpy(formatName, name);

    formatName = cleanWhiteSpaceEdges(formatName);
    printf("%s\n", formatName);
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
    for (int i = 0; i < strlen(formatName); i++) {
        if (*(formatName + i) == ' ') {
            sc++;
        }
    }
    char *res = malloc(strlen(formatName) + sc);
    for (int i = 0, j = 0; i < strlen(formatName); i++) {
        if (*(formatName + i) == ' ' && *(formatName + i - 1) != ' ') {
            *(res + j) = ' ';
            *(res + j + 1) = ' ';
            j += (isEven) ? 1 : 2;
        } else if (*(formatName + i) != ' ') {
            *(res + j) = ((*(formatName + i - 1) == ' ' || i == 0) && *(formatName + i) >= 97) ? *(formatName + i) - 32 : *(formatName + i);
            j++;
        }
    }
    *(res + strlen(res)) = '\0';
    formatName = realloc(res, strlen(res));

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


Airport *initAirportNoCode(Airport *port) {
    port = initAirport(port);
    return port;
}
