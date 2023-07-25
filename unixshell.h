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
void signal_input(int);
void _EOF_(char*);

#endif