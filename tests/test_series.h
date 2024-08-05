#include <iostream>
#include <stdexcept>
#include <string>

#include "utilities.h"

namespace tests {

class SeriesTestException : public runtime_error
{
public:
    SeriesTestException(const std::string &what_arg)
        :runtime_error(what_arg){}
};

class TestSeries : public Test
{
protected:
    void _run() override
    {
        std::cout << "\nTESTS FOR SERIES\n";
    }
};

void test_series(){
    TestSeries().run();
}

}