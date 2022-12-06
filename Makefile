run: all
	 gcc -Wall mkfile.c -o mk.o
	 ./mk.o
	 rm mk.o
	
all: projetcrypto.h mkfile.c question1.c main1.c question2.c main2.c question3.c main3.c
	 
q1: all
		gcc -Wall main1.c -o main1.o
		./main1.o
		rm main1.o
		
q2: all
		gcc -Wall main2.c -o main2.o
		./main2.o
		rm main2.o
		
q3: all
		gcc -Wall main3.c -o main3.o
		./main3.o
		rm main3.o
