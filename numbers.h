#include <cmath>
#include <iostream>

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
        Scalar _gcd {gcd(n, d)};
        this->n = n / _gcd;
        this->d = d / _gcd;
    }
    constexpr Rational(): n(1), d(1){}

    // OPERATOR OVERLOADS

    constexpr Rational operator+() const
    {
        return Rational(abs(n), d);
    }

    constexpr Rational operator-() const
    {
        return Rational(-n, d);
    }

    constexpr Rational operator+(const Rational &rhs) const
    {
        Scalar rhsD = rhs.d, lhsD = d, rhsN = rhs.n, lhsN=n;
        return Rational(lhsN*rhsD + rhsN*lhsD, lhsD*rhsD);
    }

    constexpr Rational operator*(const Rational &rhs) const
    {
        return Rational(n*rhs.n, d*rhs.d);
    }

    constexpr Rational operator-(const Rational &rhs) const
    {
        return *this + (-rhs);
    }
    
    constexpr Rational operator/(const Rational &rhs) const
    {
        return Rational(n*rhs.d, d*rhs.n);
    }
    
    Rational& operator+=(Rational &rhs)
    {
        Scalar rhsD = rhs.d, lhsD = d, rhsN = rhs.n, lhsN=n;
        lhsN = lhsN*rhsD + rhsN*lhsD;
        lhsD = lhsD * rhsD;
        Scalar _gcd = gcd(lhsN, lhsD);
        n = lhsN / _gcd;
        d = lhsD / _gcd;
    }
    Rational& operator-=(Rational &rhs)
    {
        return *this;
    }
    Rational& operator*=(Rational &rhs)
    {
        return *this;
    }
    Rational& operator/=(Rational &rhs)
    {
        return *this;
    }

    bool operator<(const Rational &rhs) const
    {
        return true;
    }
    bool operator>(const Rational &rhs) const
    {
        return true;
    }
    bool operator<=(const Rational &rhs) const
    {
        return true;
    }
    bool operator>=(const Rational &rhs) const
    {
        return true;
    }
    bool operator==(const Rational &rhs) const
    {
        return true;
    }
    bool operator!=(const Rational &rhs) const
    {
        return true;
    }

    operator int()
    {
        return int(n) / int(d);
    }

    operator double()
    {
        return double(n) / double(d);
    }

    ostream& operator<<(ostream& os)
    {
        return os;
    }

    istream& operator>>(istream& is)
    {
        return is;
    }
    
    // UTILITIES

    constexpr double pow(const Rational &lhs, const Rational &rhs) const
    {
        double lhs_numeric {double(lhs)};
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