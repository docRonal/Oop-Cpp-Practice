#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
    double Real, Imag;

public:
    // Complex() : Real(0), Imag(0) {};

    // Complex(double co)
    // {
    //     Real = co;
    //     Imag = 0;
    // };

    // Complex(double Real, double Imag)
    // {
    //     this->Real = Real;
    //     this->Imag = Imag;
    // };
    Complex(double Real = 0, double Imag = 0)
        : Real(Real), Imag(Imag) {}

    Complex &operator=(const Complex &s)
    {
        Real = s.Real;
        Imag = s.Imag;
        return *this;
    };

    Complex operator-() const
    {
        return Complex(-Real, -Imag);
    };

    Complex &operator=(double co)
    {
        Real = co;
        Imag = 0;
        return *this;
    };

    Complex operator+(const Complex &co) const
    {
        Complex n;
        n.Real = this->Real + co.Real;
        n.Imag = this->Imag + co.Imag;
        return n;
    };

    Complex &operator-=(Complex co)
    {
        Real -= co.Real;
        Imag -= co.Imag;
        return *this;
    };
    friend Complex operator/(double val, const Complex &co);

    Complex operator/(const Complex &co) const
    {
        double dziel = co.Real * co.Real + co.Imag * co.Imag;
        return Complex(
            (Real * co.Real + Imag * co.Imag) / dziel,
            (Imag * co.Real - Real * co.Imag) / dziel);
    }

    Complex &operator/=(const Complex &co)
    {
        double dziel = co.Real * co.Real + co.Imag * co.Imag;

        double newReal = (Real * co.Real + Imag * co.Imag) / dziel;
        double newImag = (Imag * co.Real - Real * co.Imag) / dziel;

        Real = newReal;
        Imag = newImag;

        return *this;
    }

    double abs()
    {
        return sqrt(pow(Real, 2) + pow(Imag, 2));
    }

    double phase()
    {
        return atan2(Imag, Real);
    }

    Complex conj()
    {
        Complex temp(Real, -this->Imag);
        return temp;
    }

    friend Complex operator-(Complex, Complex);
    friend ostream &operator<<(ostream &s, const Complex &c)
    {
        s << "(" << c.Real << "," << c.Imag << ")";
        return s;
    };
};

inline Complex operator-(Complex s1, Complex s2)
{
    Complex n(s1);
    return n -= s2;
}

inline Complex operator/(double val, const Complex &co)
{
    double dziel = co.Real * co.Real + co.Imag * co.Imag;

    double real = (val * co.Real) / dziel;
    double imag = (-val * co.Imag) / dziel;

    return Complex(real, imag);
}

#endif /* __Complex_H__ */
