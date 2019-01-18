PROG = main_complex_beispiel

FLAGS = -O2

CC = g++ -std=c++11

SRCS = main_complex_beispiel.cpp mycomplex.cpp

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

main_complex_beispiel.o: main_complex_beispiel.cpp mycomplex.h

