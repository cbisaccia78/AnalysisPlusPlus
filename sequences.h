#include <stdexcept>
#include <limits>

#include "expressions.h"

namespace analysis
{
class EndOfSequenceException : public std::out_of_range
{};

template <Arithmetic Scalar>
class SequenceGenerator
{
public:
    SequenceGenerator(Expression<Scalar> expression, unsigned long long n_begin=0, unsigned long long n_end=std::numeric_limits<unsigned long long>::max())
        : expression(expression), _n(n_begin), _end(n_end){}

    Expression<Scalar> expression;

    Scalar> operator()()
    {
        if (_n < _end)
        {
            _n++;
        }
        else 
            throw EndOfSequenceException();
    }

protected:
    unsigned long long _n;
    unsigned long long _end;

};

}