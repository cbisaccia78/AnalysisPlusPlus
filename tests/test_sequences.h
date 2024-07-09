#include <iostream>

#include "utilities.h"

namespace tests {

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