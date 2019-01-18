PROG = aufgabe2

FLAGS = -O2

CC = g++ -std=c++11

SRCS = mycomplex.cpp aufgabe2.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf *.o $(PROG)

## dependencies

my_complex.o: mycomplex.cpp mycomplex.h

aufgabe2.o: aufgabe2.cpp mycomplex.h start.h
