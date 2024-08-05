FLAGS=-std=c++20 -Wall -O3

all : analysis test_driver

analysis : main.o
	g++ $(FLAGS) -o analysis main.o

main.o : main.cpp interpreter.h numbers.h sequences.h
	g++ $(FLAGS) -c main.cpp

test_driver : tests.o
	g++ $(FLAGS) -o test_driver tests.o

tests.o : tests/tests.cpp tests/test_interpreter.h interpreter.h tests/test_numbers.h numbers.h tests/test_sequences.h  sequences.h tests/test_series.h series.h tests/utilities.h
	g++ $(FLAGS) -Itests -c tests/tests.cpp

clean :
	rm -f analysis interpretor.h.gch main.o numbers.h.gch sequences.h.gch test_driver tests.o