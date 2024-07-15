#include <iostream>
#include <stdexcept>
#include <string>

#include "utilities.h"

namespace tests {

class InterpreterTestException : public runtime_error
{
public:
    InterpreterTestException(const std::string &what_arg)
        :runtime_error(what_arg){}
};

class TestInterpreter : public Test
{
protected:
    void _run() override
    {
        std::cout << "\nTESTS FOR INTERPRETER\n";
    }
};

void test_interpreter(){
    TestInterpreter().run();
}

}