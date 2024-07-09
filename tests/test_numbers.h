#include <iostream>

#include "../numbers.h"
#include "utilities.h"

using namespace std;
using namespace analysis::numbers;

namespace tests
{

class TestRational : public Test
{
public:
    void testConstructor(){
        Rational<int> R {2, 5};
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
