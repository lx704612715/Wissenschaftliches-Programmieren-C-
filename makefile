PROG = my_complex

FLAGS = -O2

CC = g++ -std=c++11

SRCS = my_complex_test.cpp my_complex.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<

clean:
	rm -rf *.o $(PROG)

## dependencies

vector_funcs.o: my_complex.cpp my_complex.h

vec_mat_test.o: my_complex_test.cpp my_complex.h
