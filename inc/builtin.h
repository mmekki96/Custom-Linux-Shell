#ifndef BUILTIN_H
#define BUILTIN_H

typedef int (*builtin_func)(char**);

int msh_cd(char**);
int msh_exit(char **);

typedef struct 
{
    char* cmd;
    builtin_func func;
}command;

command cmds[] = {{"cd", msh_cd}, {"exit", msh_exit}};

#endif