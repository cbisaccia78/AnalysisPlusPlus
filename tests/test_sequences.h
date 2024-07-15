#include <iostream>
#include <stdexcept>
#include <string>

#include "utilities.h"

namespace tests {

class SequencesTestException : public runtime_error
{
public:
    SequencesTestException(const std::string &what_arg)
        :runtime_error(what_arg){}
};

class TestSequences : public Test
{
protected:
    void _run() override
    {
        std::cout << "\nTESTS FOR SEQUENCES\n";
    }
};

void test_sequences(){
    TestSequences().run();
}

}