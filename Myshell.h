#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/**** Headers *****/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
/**** Functions****/
extern char **environ;
extern char **environ;
extern char *token;
extern char *line;
extern char *delimiters;
extern char *command_arguments[];
void execute_user_command(void);
char *get_path_check(char *command);
int _pid(char *command_arguments[]);
void process_command(void);
int Token_input(char *input_line);
int str_program(char *arguments[]);
size_t calculate_string_length(const char *str);
void exit_shell(void);
void handle_comments(char *user_input);
char *find_executable(char *command);
void print_env(void);
void print_error_message(char *command);
void change_directory_builtin(char *target_dir);
int launch_new_process(char *arguments[]);
void handle_signal(int signal_number);
void print_env(void);
char *concatenate_strings(char *destination, char *source);
int compare_Two_strings(const char *str1, const char *str2);
#endif /* SIMPLE_SHELL_H */
