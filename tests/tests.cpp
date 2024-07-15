#include <iostream>
#include <exception>

#include "test_interpreter.h"
#include "test_numbers.h"
#include "test_sequences.h"

using namespace tests;

int main(int argc, char **argv)
{
    try
    {
        test_interpreter();
        test_numbers();
        test_sequences();
    }
    catch(const InterpreterTestException &e)
    {
        std::cerr << "Error in interpreter tests:\n";
        std::cerr << e.what() << '\n';
        std::cerr << LINE_BREAK;
    }
    catch(const NumberTestException &e)
    {
        std::cerr << "Error in number tests:\n";
        std::cerr << e.what() << '\n';
        std::cerr << LINE_BREAK;
    }
    catch(const SequencesTestException &e)
    {
        std::cerr << "Error in sequences tests:\n";
        std::cerr << e.what() << '\n';
        std::cerr << LINE_BREAK;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << LINE_BREAK;
    }
    
}