# Simple Shell

This is a simple UNIX command line interpreter that adheres to specific requirements. Follow the instructions below to understand and implement the shell in your GitHub repository.

- [Usage](#usage)
- [Features](#features)
  - [Task 1: Basic Shell](#task-1-basic-shell)
  - [Task 2: Command Lines with Arguments](#task-2-command-lines-with-arguments)
  - [Task 3: PATH Handling](#task-3-path-handling)
  - [Task 4: Exit Built-in](#task-4-exit-built-in)
  - [Task 5: Env Built-in](#task-5-env-built-in)
  - [Task 6: Custom getline Function](#task-6-custom-getline-function)
  - [Task 7: No strtok](#task-7-no-strtok)
- [Instructions](#instructions)

## Usage

$ ./hsh

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections, or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
Handle the "end of file" condition (Ctrl+D).
Features
Task 1: Basic Shell
Task 2: Command Lines with Arguments
Task 3: PATH Handling
Task 4: Exit Built-in
Task 5: Env Built-in
Task 6: Custom Getline Function
Task 7: No Strtok
Instructions
-Files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89.
-Your shell should not have any memory leaks.
-Use system calls only when you need to.
-Your program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (e.g., $ ./hsh: 1: qwerty: not found).
-The shell should work in both interactive and non-interactive modes.
-The list of allowed functions and system calls includes:
access, chdir, close, closedir, execve, exit, _exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, read, readdir, signal, stat (__xstat), lstat (__lxstat), fstat (__fxstat), wait, waitpid, wait3, wait4, write.
