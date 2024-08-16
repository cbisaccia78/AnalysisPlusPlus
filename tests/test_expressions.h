#include <iostream>
#include <stdexcept>
#include <string>

#include "utilities.h"

namespace tests {

class ExpressionTestException : public runtime_error
{
public:
    ExpressionTestException(const std::string &what_arg)
        :runtime_error(what_arg){}
};

class TestExpression : public Test
{
protected:
    void _run() override
    {
        std::cout << "\nTESTS FOR EXPRESSIONS\n";
    }
};

void test_expressions(){
    TestExpression().run();
}

}