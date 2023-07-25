#ifndef UNIXSHELL
#define UNIXSHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

void show_prompt(void);
char **line_token(char*, const char*);
void signal_input(int);
void _EOF_(char*);
void exit_shellf(char**);

#endif