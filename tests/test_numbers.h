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
    void testSubtraction(){
        cout << "Testing subtraction... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        auto res {R1 - R2};
        if(res != Rational<int>(3, 20))
            throw NumberTestException("Subtraction broken.");

        cout << "passed\n"; 
            
    }
    void testMultiplication(){
        cout << "Testing multiplication... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        auto res {R1 * R2};
        if(res != Rational<int>(1, 10))
            throw NumberTestException("Multiplication broken.");

        cout << "passed\n"; 
    }
    void testDivision(){
        cout << "Testing division... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        auto res {R1 / R2};
        if(res != Rational<int>(8, 5))
            throw NumberTestException("Division broken.");

        try
        {
            R1 / Rational<int>(0);
        }
        catch (const runtime_error& e)
        {
            cout << "passed\n";
            return;
        }
        catch (const std::exception &e)
        {
            throw NumberTestException("Wrong error type thrown on divide by zero");
        }

        throw NumberTestException("No error thrown on divide by zero");
    }
    void testAdditionAssignment(){
        cout << "Testing addition assignment... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        R1 += R2;
        if(R1 != Rational<int>(13, 20))
            throw NumberTestException("Addition assignment broken.");

        cout << "passed\n"; 
    }
    void testSubtractionAssignment(){
        cout << "Testing subtraction assignment... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        R1 -= R2;
        if(R1 != Rational<int>(3, 20))
            throw NumberTestException("Subtraction assignment broken.");

        cout << "passed\n"; 
    }
    void testMultiplicationAssignment(){
        cout << "Testing multiplication assignment... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        R1 *= R2;
        if(R1 != Rational<int>(1, 10))
            throw NumberTestException("Multiplication assignment broken.");

        cout << "passed\n"; 
    }
    void testDivisionAssignment(){
        cout << "Testing division assignment... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        R1 /= R2;
        if(R1 != Rational<int>(8, 5))
            throw NumberTestException("Division assignment broken.");

        cout << "passed\n"; 
    }
    void testLessThan(){
        cout << "Testing less than... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        if( R1 < R2 || R1 < R1)
            throw NumberTestException("less than broken.");

        cout << "passed\n"; 
    }
    void testLessThanEqualTo(){
        cout << "Testing less than equal to... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        if( R1 <= R2 || !(R1 <= R1))
            throw NumberTestException("less than equal to broken.");

        cout << "passed\n"; 
    }
    void testGreaterThan(){
        cout << "Testing greater than... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        if( R2 > R1 || R1 > R1)
            throw NumberTestException("greater than broken.");

        cout << "passed\n"; 
    }
    void testGreaterThanEqualTo(){
        cout << "Testing greater than equal to... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        if( R2 >= R1 || !(R1 >= R1))
            throw NumberTestException("greater than equal to broken.");

        cout << "passed\n"; 
    }
    void testEqual(){
        cout << "Testing equality... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        if( R2 == R1 || !(R1 == R1))
            throw NumberTestException("equality broken.");

        cout << "passed\n"; 
    }
    void testNotEqual(){
        cout << "Testing greater than... ";

        Rational<int> R1(2,5);
        Rational<int> R2(1,4);
        if( R2 > R1 || R1 > R1)
            throw NumberTestException("less than broken.");

        cout << "passed\n"; 
    }
    void testInputOperator(){}
    void testOutputOperator(){}
    void testPow(){}
    void testGcd(){}

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
        testPow();
        testGcd();
    }
};

void test_numbers(){
    TestRational().run();
}

}
