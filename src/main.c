#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "tokenize.h"
#include "builtin.h"

int main() {
	char cmd[256];
	char delim[] = " \n";
	while(1) {
		int i = 0;
		int found = 0;
		int stat = -1;
		char* tok[10];
		char path[100];
		int size = sizeof(cmds)/sizeof(command);
		printf("$msh (%s) -> ", getcwd(path, sizeof(path)));
		fgets(cmd, sizeof(cmd), stdin);
		tokenize(cmd, tok);
		if (tok[0] == NULL) continue;
		while ((i < size) && !found) {
			if (!strcmp(tok[0], cmds[i].cmd)) {
				stat = cmds[i].func(tok);
				found = 1;
			} else {
				i++;
			}
		}
		if (stat == 1) {
			break;
		} else if (!stat) {
			continue;
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
