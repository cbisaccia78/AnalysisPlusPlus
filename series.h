#include "expressions.h"

namespace analysis
{

template <Arithmetic Scalar>
class SeriesGenerator
{
public:
    SeriesGenerator(Expression<Scalar> expression)
        : expression(expression){}

    Expression<Scalar> expression;
};

}