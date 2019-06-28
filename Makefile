CC = g++
FLAGS = -std=c++14 -Wall -g
OBJS = linear_binary.o #object code not executable file
# OUT_EXE = .exe file name

all: linearVsBinary
linearVsBinary: driver.cpp linear_binary.o
	$(CC)	$(FLAGS) driver.cpp	-o linearVsBinary $(OBJS)

linear_binary.o: linear_binary.cpp linear_binary.h
	$(CC)	$(FLAGS) -c linear_binary.cpp	-o linear_binary.o

clean:
	rm	*.o	linearVsBinary linearVsBinary.scr linearVsBinary.tar

tar:
	tar	cf linearVsBinary.tar linearVsBinary.scr Makefile	driver.cpp linear_binary.h linear_binary.cpp
