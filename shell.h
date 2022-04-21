#ifndef _SHELL_
#define _SHELL_
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define BUFSIZE 5024
#define DELIMITERS " =:;\t\"\n+"
#define UNUSED(x) (void)(x)

extern char **environ;
/*static char **last_environ;*/
/**
 * struct build_in - Struct of pointers to funtions
 * @build_in: build_in identifier
 * @func: function associated
 */

typedef struct build_in
{
	char *build_in;
	int (*func)(char *line, char **args, int *fail);
} build_in_t;
int _isalpha(char *s);
int _atoi(char *s);
char *_getenv(const char *name);
char *read_input(int *fail);
char *_getline();
char *_strtok(char *str, char *d);
void shell_start(char *exe);
char **av_line_saver(char *line);
int _process_launcher(char **args, int *fail);
int _cd(char *line, char **args, int *fail);
int hlp(char *line, char **args, int *fail);
int ext(char *line, char **args, int *fail);
int _execute(char *line, char **args, char *exe, int count, int *fail);
int (*get_build_in(char *build_in))(char *line, char **args, int *fail);
int search_no_build_in(char **args, int *fail);
int _env(char *line, char **args, int *fail);
size_t _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
void _strcat(char *s1, char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);
void _realloc(char *ptr, int new_size);
char *_number_to_char(int n);
int _setenv(char *line, char **args, int *fail);
int _unsetenv(char *line, char **args, int *fail);
int _strcmp(const char *s1, const char *s2);
#endif
