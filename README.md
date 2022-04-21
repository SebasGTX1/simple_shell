# simple_shell
In this repo, Ricardo Montaña and me created our own Shell!! Yeahh!!

## SeRiShell C17 0x16.C

This is the manpage of the SeRiShell project in Holberton School

NAME

       SeRiShell - Standard input line for receiving instructions via commands

SYNOPSIS

       [COMMAND] [FLAGS]

ABOUT SERISHELL PROJECT

       The SeRiShell project is just a small version of the linux shell.
       This project was developed in the C programming language, through
       which many functionalities that a real shell does can be executed.

DESCRIPTION

       The shell is a program that receives instructions from the keyboard
       through the terminal and passes them to the operating system for execution.

       SeRiShell()

       The  SeRiShell  program  displays a prompt with standard input line for receiving
       instructions vía commands like the linux shell interpreter.  For  example,  if  a
       user enters ls then the shell executes the ls command.

       man ./man_1_simple_shell Display this manual

WORK FLOW

	<img src="https://www.bodegalibre.com/storage/flowchart_simple_shell.jpg">


OPTIONS

       The ls command can be used with the following flags:

       -a   List directory contents including hide files

       -l   List directory contents using a long format

EXAMPLES

       SeRiShell:/simple_shell$ pwd    Shows current directory

       SeRiShell:/simple_shell$ ls   List directory contents

       SeRiShell:/simple_shell$ cd   Move the cursor at home directory

       SeRiShell:/simple_shell$ cd [Directory] Move the cursor to a lower directory

       SeRiShell:/simple_shell$ cd ..     Move the cursor to the top directory

       SeRiShell:/simple_shell$ cd - Move the cursor to the previous directory

EXIT VALUES ...

       This is the list of output values and their meaning.

SEE ALSO

       Full documentation at: <https://github.com/SebasGTX1/simple_shell>

       Relative commands and functions

BUGS

       Here is a small list of bugs that were fixed.

FILES

       Files included are:

       shell_start.c

       shell.h

       _execute_process.c

       _getenv.c

       _getline.c

       _process_luncher.c

       _read_input.c

       _search_no_build_in.c

       _strings.c

       _strtok.c

       av_line_saver.c

       build_ins.c

       build_ins_2.c

       get_build_in.c

       memory_allocation.c

       num_to_char.c

HISTORY

       Since the alpha version no new versions have been made.

AUTHORS

       Written by Sebastián García & Ricardo Montaña.

       21 April 2022

COPYRIGHT

       © All rights reserved
