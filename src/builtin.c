#include <unistd.h>
#include <stdio.h>

int msh_cd(char** args) {
    if (args[1] == NULL) {
        chdir("/");
    } else if (chdir(args[1])) {
        printf("[!] Directory not found\n");
    }
    return 0;
}

int msh_exit(char** args) {
    return 1;
}
