# Lamports-Logical-Clock
This program contains two components and tests for both: 
1. Verifying whether or not a matrix input is valid for Lamport's Logical Clock
2. Calculating a valid Lamport's Logical Clock matrix for a given input.

Test cases are included in main.cpp.<br />
The algorithm calculate is included in the CalculateClock.cpp file.<br />
The algorithm verify is included in the VerifyClock.cpp file.<br />
The PDF 'pseudocode.pdf' includes my pseudocode for both algorithms I created.<br />
The Makefile will generate object code for each of the relevant files and will create an executable file called 'clock'

The tests directory contains output for the tests given in main.cpp.<br />
The text file project_tests.txt includes the outputs for a limited number of cases.<br />
The text file comprehensive_tests.txt includes the output for additional, tricky cases.<br />
By default, my program prints to stdout, but you can redirect the output to a text file by running the linux command<br /><br />
./clock > name_of_file.txt <br /><br />
assuming the program was compiled so that the executable is clock (as it is written in the makefile)
				
The output is split between the two algorithms with clear deliminators between the two.

Enjoy! :)