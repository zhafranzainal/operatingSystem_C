# operatingSystem_C
Implement a command-line (text-based) user interface shell.

## Introduction
This is an implementation of a Linux shell written in C language.

## Run the shell
1. Run the command `cd` inside the “src” directory.
2. Run the command `make`.
3. Run `./shell` to get started (prompt `username@hostname:working_directory_$_` will be appeared).
4. Run command in the shell.
5. In order to exit, run `exit`.

## Features

### Built-in commands

1. `ls`
    
    - Lists all the files and directories in the specified directory in alphabetical order.
    - Variations such as `ls, ls . , ls ..` also work.

2. `cd [directory]`
    
    - Changes directory to the directory specified, throws an error if the directory does not exist.

3. `grep "text"`
    
    - Searches text and strings in the specified file.

4. `exit [n]`

    - Exits the shell.

## Additional Features (Not done yet)

1. Background Execution

    - If an ampersand (&) is at the end of command line entered by the user (i.e., the last non-whitespace character before enter is pressed), the command should be executed in the background.

2. Input-Output Redirection & Piping

    - Handles `<`, `>`, `>>`, and `|` operators appropriately, wherever they are in the command
    - Throws error if syntax is incorrect

3. Command Recall using ‘UP’ arrow key

    - ‘UP’ key with the ‘ENTER’ key causes a new prompt to be displayed with the previous command and then that command is executed. (similar to normal Ubuntu environment).
    - Pressing ‘UP’ key ‘n’ times consecutively leads to the n​th ​ previous command getting executed.

## Restrictions

• The code is written in C and compiled with the version above 9.3.0 of gcc.
• execv() is the only call of the exec*() family that is used (e.g., use of execvp() is not permitted)