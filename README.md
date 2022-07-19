# tic-tac-toe
A tic-tac-toe game, written in C.

Command line only.

Compile: gcc -o \<filename\> tic.c (for Linux - do not name the executable file "tic", as there is already a command named "tic" in linux), gcc -o \<filename\>.exe tic.c (for Windows with MinGW-gcc) - where \<filename\> is the name of the executable file you want to create. 

If you use Windows, change lines 68, 91 from "system("clear");" to "system("cls");" before compiling. 

Run with \<filename\>.exe (Windows) or ./\<filename\> (Linux). Use option "-h" to display a help message. 
