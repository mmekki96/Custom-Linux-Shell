#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	char cmd[256];
	char delim[] = " \n";
	while(1) {
		int i = 0;
		char* tok[10];
		printf("myshell>> ");
		fgets(cmd, sizeof(cmd), stdin);
		char* t = strtok(cmd,delim);
		while (t) {
			tok[i++] = t;
			t = strtok(NULL, delim);
		}
		tok[i] = NULL;
		if (!strcmp(tok[0], "exit")) {
			break;
		} else {
			if (fork() == 0) {
				execvp(tok[0], tok);
				return 1;
			} else {
				wait(NULL);			
			}
		}
		
	}			
	return 0;
}
