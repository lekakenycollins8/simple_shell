#ifndef SHELL_H
#define SHELL_H

/* header files */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>

/* shell macros */

#define PRINTPROMPT(p) write(STDOUT_FILENO, p, custom_strlen(p))
#define INPUT_BUFFER_SIZE 1024
#define TOKEN_BUFFER_SIZE 100
#define TOKEN_DELIMETER "\t\r\n\a"
#define PATH_DELIMETER ":"

/* environment */
extern char **environ;
char *_getenv(char *name);

/* string custom functions */

int custom_strncmp(const char *str1, const char *str2, size_t n);
size_t custom_strlen(char *s);
char *custom_strcpy(char *dest, const char *src);
int custom_strcmp(const char *str1, const char *str2);
char *custom_strcat(char *dest, char *src);
char *custom_strdup(char *source);
char *custom_strtok(char *str, const char *delim);
bool is_delimiter(char c, const char *delim);

/* function to read input from both interactive and non-interactive shell */
char *read_input(void);
char *read_line(void);
char **split_line(char *line);
int _putchar(char c);

/* functions that handles shell execute */

void handle_child_process (char **args, char *line_value);
void handle_parent_process(pid_t child_pid, char **args, char *line_value);
void execute_command(char **args, char *line_value);
void process_command(char **args, char *line_value);

/* builtin implementation functions */

int custom_atoi(char *str, int *valid);
void exit_shell(char *line_value, char **args);
void execute_env(void);

/* realloc and its helper functions */
void *fill_with_byte(void *array, int byte, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* error handling functions */

char *int_to_string(int num);
void fprintf_stdout(const char *format, ...);

#endif /* SHELL_H */
