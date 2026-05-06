#include <string.h>

void tokenize(char* cmd, char** dest) {
    char delim[] = " \n";
    char* t = strtok(cmd, delim);
    int i = 0;
    while (t != NULL) {
        dest[i++] = t;
        t = strtok(NULL, delim);
    }
    dest[i] = NULL;
}