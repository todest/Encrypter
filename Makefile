SHELL=cmd.exe
OBJS = DE.o EN.o Decrypt.o Encrypt.o Former.o Main.o
Main: $(OBJS)
	g++ -o main $(OBJS)
Main.o:
	g++ -c Main.cpp
DE.o:
	g++ -c DE.cpp
EN.o:
	g++ -c EN.cpp
Decrypt.o:
	g++ -c Decrypt.cpp
Encrypt.o:
	g++ -c Encrypt.cpp
Former.o:
	g++ -c Former.cpp
clean:
	del $(OBJS)
	del main.exe