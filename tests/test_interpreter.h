#include <iostream>

#include "utilities.h"

namespace tests {

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