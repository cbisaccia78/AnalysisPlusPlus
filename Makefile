all : analysis test_driver

analysis : main.o
	g++ -Wall -o analysis main.o

main.o : main.cpp interpreter.h numbers.h sequences.h
	g++ -Wall -c main.cpp

test_driver : tests.o
	g++ -Wall -o test_driver tests.o

tests.o : tests/tests.cpp tests/test_interpreter.h tests/test_numbers.h tests/test_sequences.h tests/utilities.h
	g++ -Wall -Itests -c tests/tests.cpp

clean :
	rm -f analysis interpretor.h.gch main.o numbers.h.gch sequences.h.gch test_driver tests.o