#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include "numbers.h"

namespace analysis
{

class Symbol
{}; //Constant, Variable, Operator, Grouper

class Constant : public Symbol
{};//[0-9]*

class Variable : public Symbol
{}; //[a-z][A-Z]

class Operator : public Symbol
{}; // +, -, /, *, ^

class Function : public Symbol
{}; // cos, sin, tan, exp, exp10, exp2, log, log10, log2, pow, ceil, floor, fmod, fabs, fmax, fmin, sum, product, integral

class Grouper : public Symbol
{}; //parens, brackets, braces, absolute value bars

class Index : public Symbol
{};

class OpenParenthesis : public Symbol
{};

class ClosedParenthesis : public Symbol
{};


template <Arithmetic Scalar>
class Expression
{
public:
    Expression(const std::string &expression_string)
    {
        std::istringstream expression_stream {expression_string};

        Symbol s;
        while (expression_stream >> s)
        {
            if (dynamic_cast<Parenthesis *>(&s))
        }
    }

    Scalar operator()(const Scalar &input) const
    {

    }

protected:

};

}