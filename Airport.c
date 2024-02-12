#include "Airport.h"

Airport* initAirport(){
    Airport* airport = (Airport*)malloc(sizeof(Airport));
    getAirportCode(airport->code);

    return airport;
}

void getAirportCode(char *airportCode) {
    const int expectedLength = 3;
    const int maxLength = 0xff;

    while (true) {
        printf("Enter airport code - %d UPPER CASE letters: ", expectedLength);

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
                    puts("All characters must be upper case letters.");
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





