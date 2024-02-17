#include "generalFunctions.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *getDynamicStr(char *s) {
    int len = strlen(s);
    char *retStr = (char *)malloc(len + 1);
    if (s == NULL) {
        retStr = NULL;
    } else {
        strcpy(retStr, s);
    }
    return retStr;
}

int wordCount(char *str) {
    if (strlen(str) == 1) {
        return isspace(*str);
    }
    int wc = 1;
    for (int i = 1; i < (int)strlen(str); i++) {
        if (*(str + i) == ' ' && (*(str + i - 1) != ' ')) {
            wc++;
        }
    }
    return wc;
}

char *cleanWhiteSpaceEdges(char *str) {
    char *stret = str;
    int i = 0, j = strlen(str);
    while (*(str + j - 1) == ' ') {
        j--;
    }
    while (*(str + i) == ' ') {
        i++;
    }
    stret = malloc(j - i + 1);
    strncpy(stret, str + i, j - i);
    *(stret + j - i) = '\0';
    return stret;
}

char* addUnderlines(char *formatName) {
    int l = strlen(formatName) * 2 - 1;
    formatName = realloc(formatName, l);
    for (int i = strlen(formatName) - 1, j = l - 1; i >= 0; j--, i--) {
        *(formatName + j) = (*(formatName + i) >= 97) ? *(formatName + i) - 32 : *(formatName + i);
        j--;
        *(formatName + j) = '_';
    }
    *(formatName + l-2) = '\0';

    return formatName;
}

char *rmWhiteSpace(char *name) {
    char *formatName = malloc(strlen(name));
    strcpy(formatName, name);
    for (int i = 0, j = 0; j < (int)strlen(formatName); j++, i++) {
        if (isspace(*(formatName + i))) {
            do {
                i++;
            } while (isspace(*(formatName + i)));
        }
        if (i != j) {
            *(formatName + j) = *(formatName + i);
        }
    }
    return formatName;
}
