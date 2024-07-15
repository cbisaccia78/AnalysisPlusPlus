#include <iostream>
#include <stdexcept>
#include <string>

#include "../numbers.h"
#include "utilities.h"

using namespace std;
using namespace analysis::numbers;

namespace tests
{

class NumberTestException : public runtime_error
{
public:
    NumberTestException(const std::string &what_arg)
        :runtime_error(what_arg){}
    
    NumberTestException()
        :runtime_error("Generic Number Test Exception."){}
};

class TestRational : public Test
{
public:
    void testConstructor(){
        Rational<int> R {2, 5};
        if (R.n != 2 || R.d != 5)
            throw NumberTestException("Error in constructor.");
        
        R = Rational<int>(4, 10);
        if (R.n != 2 || R.d != 5)
            throw NumberTestException("Fraction not reduced in constructor.");
    }
    void testUnaryPlus(){}
    void testUnaryMinus(){}
    void testAddition(){}
    void testSubtraction(){}
    void testMultiplication(){}
    void testDivision(){}
    void testAdditionAssignment(){}
    void testSubtractionAssignment(){}
    void testMultiplicationAssignment(){}
    void testDivisionAssignment(){}
    void testLessThan(){}
    void testLessThanEqualTo(){}
    void testGreaterThan(){}
    void testGreaterThanEqualTo(){}
    void testEqual(){}
    void testNotEqual(){}
    void testInputOperator(){}
    void testOutputOperator(){}

protected:
    void _run() override
    {
        std::cout << "\nTESTS FOR RATIONAL\n";
        testConstructor();
        testUnaryPlus();
        testUnaryMinus();
        testAddition();
        testSubtraction();
        testMultiplication();
        testDivision();
        testAdditionAssignment();
        testSubtractionAssignment();
        testMultiplicationAssignment();
        testDivisionAssignment();
        testLessThan();
        testLessThanEqualTo();
        testGreaterThan();
        testGreaterThanEqualTo();
        testEqual();
        testNotEqual();
        testInputOperator();
        testOutputOperator();
        
    }
};

void test_numbers(){
    TestRational().run();
}

}
