PROG = my_complex

FLAGS = -O2

CC = g++ -std=c++11

SRCS = mycomplex_test.cpp mycomplex.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf *.o $(PROG)

## dependencies

my_complex.o: my_complex.cpp mycomplex.h

my_complex_test.o: my_complex_test.cpp mycomplex.h
