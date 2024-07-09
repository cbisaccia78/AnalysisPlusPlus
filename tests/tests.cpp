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
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}