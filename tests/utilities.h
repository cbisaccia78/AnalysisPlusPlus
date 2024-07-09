#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

namespace tests
{

    string LINE_BREAK {"-----------------------------\n"};

    class Test
    {
    public:
        void run()
        {
            cout << LINE_BREAK;
            this->_run();
            cout << "All tests passed!\n";
            cout << LINE_BREAK;
        }
    protected:
        virtual void _run() = 0;
    };

    class TestFailureException : public std::runtime_error
    {
    public:
        TestFailureException(const std::string &what_arg)
            : std::runtime_error(what_arg){}
    };

}