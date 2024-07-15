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
        cout << "Testing constructor... ";

        Rational<int> R {2, 5};
        if (R.n != 2 || R.d != 5)
            throw NumberTestException("Error in constructor.");
        
        R = Rational<int>(4, 10);
        if (R.n != 2 || R.d != 5)
            throw NumberTestException("Fraction not reduced in constructor.");

        try
        {
            Rational<int> R {2, 0};
        }
        catch (const runtime_error& e)
        {
            cout << "passed\n";
            return;
        }
        catch (const std::exception &e)
        {
            throw NumberTestException("Wrong error type thrown on zero denominator.");
        }

        throw NumberTestException("No error thrown on zero denominator.");
    }
    void testUnaryPlus(){
        cout << "Testing unary plus... ";

        Rational<int> R(-1);
        R = -R;
        if(R.n != 1)
            throw NumberTestException("Unary plus broken.");

        cout << "passed\n";
    }
    void testUnaryMinus(){
        cout << "Testing unary minus... ";
        Rational<int> R;
        int num_prev {R.n};
        R = -R;
        if(R.n != -num_prev)
            throw NumberTestException("Unary minus broken.");

        cout << "passed\n";
    }
    void testAddition(){
        cout << "Testing addition... ";

        Rational<int> R1(1,4);
        Rational<int> R2(2,5);
        auto res {R1 + R2};
        if(res != Rational<int>(13, 20))
            throw NumberTestException("Addition broken."); 
            
        
        R2 = Rational<int>(1,4);
        res = R1 + R2;
        if(res != Rational<int>(1,2))
            throw NumberTestException("Post-addition fraction reduction broken.");

        cout << "passed\n";
    }
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
