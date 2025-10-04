#Name:			Matthew Wilson
#Email:			mlw0420@unt.edu
#Course:		CSCE 3550.001
#Date:			4-18-22
#Description:	Makefile for project 2.

proj2:	mlw0420_proj2.o decrypt.o
	g++ -o proj2 decrypt.o mlw0420_proj2.o
	
decrypt.o: decrypt.cpp decrypt.h
	g++ -c -Wall -o decrypt.o decrypt.cpp
	
mlw0420_proj2.o: mlw0420_proj2.cpp decrypt.h
	g++ -c -Wall -o mlw0420_proj2.o mlw0420_proj2.cpp
	
clean:
	rm *.o proj2