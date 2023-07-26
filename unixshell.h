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
void _EOF_(char *);
void exit_shellf(char **);

int _strcmp(char *, char *);
int _strlen(char *);
char *_strcpy(char *, char *);
int _atoi(char *);
char *_strcat(char *, char *);
char *_strtok(char *, const char *);
size_t check_delim(char, const char *);
void child_process(char **, char *, char **, int);
int change_dir(const char *path);

void exec_command(char **, char *, char **, int);
void print_env(char **);
char **get_path(char **);
void msgerror(char *, int, char **);

char **line_token(char *, const char *);

void memfree(char **);
void memfree_exit(char **);

char *_getline();
char *enter(char *);
char *void_space(char *);
void void_hash(char *);

#endif
