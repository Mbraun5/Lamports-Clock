# Lamports-Logical-Clock
This program contains two components and tests for both: Verifying whether or not a matrix input is valid for Lamport's Logical Clock and Calculating a valid Lamport's Logical Clock matrix for a given input.

Test cases are included in main.cpp.
The algorithm calculate is included in the CalculateClock.cpp file.
The algorithm verify is included in the VerifyClock.cpp file.

The PDF 'pseudocode.pdf' includes my pseudocode for both algorithms I created.
The Makefile will generate object code for each of the relevant files and will create an executable file called 'clock'

The text file project_tests.txt includes the outputs for only the test cases you requested.
The text file comprehensive_tests.txt includes the outputs for the test cases you requested in addition to several more, including some tricky ones.
By default, my program prints to stdout, but you can redirect the output to a text file by running
					./clock > name_of_file.txt

The output is split between the two algorithms with clear deliminators between the two.

In comprehensive_tests.txt,
	The first two examples for Algorithm Calculate are the ones requested with the program, but I included additional tests that I made myself.
	The first three examples for Algorithm Verify are the ones requested with the program, but I included additional tests that I made myself.

Thank you! :)