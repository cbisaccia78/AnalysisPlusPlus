#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace analysis
{
namespace numbers
{

template <typename Scalar>
class Rational
{
public:

    // CONSTRUCTORS

    constexpr Rational(const Scalar &n, const Scalar &d=1)
    {
        if (d == Scalar(0))
            throw runtime_error("Cannot have 0 in denominator.");

        Scalar _gcd {gcd(n, d)};
        this->n = n / _gcd;
        this->d = d / _gcd;
    }
    constexpr Rational(): n(1), d(1){}

    // OPERATOR OVERLOADS

    constexpr Rational<Scalar> operator+() const
    {
        return Rational<Scalar>(abs(n), d);
    }

    constexpr Rational<Scalar> operator-() const
    {
        return Rational<Scalar>(-n, d);
    }

    constexpr Rational<Scalar> operator+(const Rational<Scalar> &rhs) const
    {
        Scalar rhsD = rhs.d, lhsD = d, rhsN = rhs.n, lhsN=n;
        return Rational<Scalar>(lhsN*rhsD + rhsN*lhsD, lhsD*rhsD);
    }

    constexpr Rational<Scalar> operator*(const Rational<Scalar> &rhs) const
    {
        return Rational<Scalar>(n*rhs.n, d*rhs.d);
    }

    constexpr Rational<Scalar> operator-(const Rational<Scalar> &rhs) const
    {
        return *this + (-rhs);
    }
    
    constexpr Rational<Scalar> operator/(const Rational<Scalar> &rhs) const
    {
        return Rational<Scalar>(n*rhs.d, d*rhs.n);
    }
    
    Rational<Scalar>& operator+=(Rational<Scalar> &rhs)
    {
        Scalar rhsD = rhs.d, lhsD = d, rhsN = rhs.n, lhsN=n;
        lhsN = lhsN*rhsD + rhsN*lhsD;
        lhsD = lhsD * rhsD;
        Scalar _gcd = gcd(lhsN, lhsD);
        n = lhsN / _gcd;
        d = lhsD / _gcd;
        return *this;
    }
    Rational<Scalar>& operator-=(Rational<Scalar> &rhs)
    {
        return *this;
    }
    Rational<Scalar>& operator*=(Rational<Scalar> &rhs)
    {
        return *this;
    }
    Rational<Scalar>& operator/=(Rational<Scalar> &rhs)
    {
        return *this;
    }

    bool operator<(const Rational<Scalar> &rhs) const
    {
        return true;
    }
    bool operator>(const Rational<Scalar> &rhs) const
    {
        return true;
    }
    bool operator<=(const Rational<Scalar> &rhs) const
    {
        return true;
    }
    bool operator>=(const Rational<Scalar> &rhs) const
    {
        return true;
    }
    bool operator==(const Rational<Scalar> &rhs) const
    {
        return (this->n == rhs.n) && (this->d == rhs.d);
    }
    bool operator!=(const Rational<Scalar> &rhs) const
    {
        return !(*this == rhs);
    }

    operator int()
    {
        return int(n) / int(d);
    }

    operator double()
    {
        return double(n) / double(d);
    }

    friend ostream& operator<<(ostream& os, const Rational<Scalar> &rhs)
    {
        os << rhs.n << '/' << rhs.d;
        return os;
    }

    friend istream& operator>>(istream& is, const Rational<Scalar> &rhs)
    {
        return is;
    }
    
    // UTILITIES

    constexpr double pow(const Rational<Scalar> &rhs) const
    {
        double lhs_numeric {double(*this)};
        double rhs_numeric {double(rhs)};
        return std::pow(lhs_numeric, rhs_numeric);
    }

    constexpr Scalar gcd(const Scalar& a, const Scalar& b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    Scalar n, d;
};

}
}