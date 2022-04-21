# simple_shell
In this repo, Ricardo Montaña and me created our own Shell!! Yeahh!!

### Features

**Table of Contents**

Table of contents
What is the shell?
About this project
Essential Functionalities of the Simple Shell
File description
List of allowed functions and system calls for this project
USAGE
Example of Usage
-*/-*/-*/-*/-*/-*/-*/-*/-*/-*/-*/-/-


<link rel="stylesheet" href="editormd/css/editormd.css" />
<div id="test-editor">
    <textarea style="display:none;">### Editor.md

**Editor.md**: The open source embeddable online markdown editor, based on CodeMirror & jQuery & Marked.
    </textarea>
</div>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
<script src="editormd/editormd.min.js"></script>
<script type="text/javascript">
    $(function() {
        var editor = editormd("test-editor", {
            // width  : "100%",
            // height : "100%",
            path   : "editormd/lib/"
        });
    });
</script>



-*/-*/-*/-*/-*/-*/-*/-/-/-/-/-*/-*/-*/

TEAM





SeRiShell(C17 0x16. C)                                            SeRiShell(C17 0x16. C)

This is the manpage of the SeRiShell project in Holberton School

NAME
       SeRiShell - Standard input line for receiving instructions via commands

SYNOPSIS
       [COMMAND] [FLAGS]

DESCRIPTION
       SeRiShell()

       The  SeRiShell  program  displays a prompt with standard input line for receiving
       instructions vía commands like the linux shell interpreter.  For  example,  if  a
       user enters ls then the shell executes the ls command.

       man ./man_1_simple_shell Display this manual

OPTIONS
       Un listado de las posibles opciones y qué hace cada una.

EXAMPLES
       SeRiShell:/simple_shell$ ls   List directory contents

       SeRiShell:/simple_shell$ ls -a     List directory contents including hide files

       SeRiShell:/simple_shell$ ls -l     List directory contents using a long format

       SeRiShell:/simple_shell$ cd   Move the cursor at home directory

       SeRiShell:/simple_shell$ cd [Directory] Move the cursor to a lower directory

       SeRiShell:/simple_shell$ cd ..     Move the cursor to the top directory

       SeRiShell:/simple_shell$ cd - Move the cursor to the previous directory

EXIT VALUES
       Posibles códigos de retorno y su significado.

SEE ALSO
       Full documentation at: <https://github.com/SebasGTX1/simple_shell>

       Relative commands and functions
BUGS
       Lista de bugs que han presentado versiones anteriores.

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
       Historial de cambios.

AUTHORS
       Written by Sebastián García & Ricardo Montaña.

       21 April 2022

COPYRIGHT
       Especificar la información del copyright.









