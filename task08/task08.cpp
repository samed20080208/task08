#include<iostream>
#include<cassert>

using namespace std;
class Fraction
{
private:
    int _numerator;
    int _denominator;
public:
    Fraction(int num, int don) : _numerator(num), _denominator(don) {}

    Fraction(const Fraction& other) : _numerator(other._numerator), _denominator(other._denominator)
    {
        cout << "copy ctor" << endl;
    }

    Fraction Multiply(const Fraction& other)
    {
        int don = this->_denominator * other._denominator;
        int num = this->_numerator * other._numerator;

        return Fraction(num, don);
    }
    Fraction Add(const Fraction& other)
    {
        int don = this->_denominator;
        int num = this->_numerator + other._numerator;
        if (this->_denominator != other._denominator)
        {
            don = this->_denominator * other._denominator;
            num = this->_numerator * other._denominator + this->_denominator * other._numerator;
        }
        return Fraction(num, don);
    }
    Fraction Minus(const Fraction& other)
    {
        int don = this->_denominator;
        int num = this->_numerator + other._numerator;
        if (this->_denominator != other._denominator)
        {
            don = this->_denominator * other._denominator;
            num = this->_numerator * other._denominator - this->_denominator * other._numerator;
        }
        return Fraction(num, don);
    }
    Fraction Divide(const Fraction& other)
    {
        int don = this->_denominator * other._numerator;
        int num = this->_numerator * other._denominator;
        return Fraction(num, don);
    }

    Fraction operator+(const Fraction& other)
    {
        int don = this->_denominator;
        int num = this->_numerator + other._numerator;
        if (this->_denominator != other._denominator)
        {
            don = this->_denominator * other._denominator;
            num = this->_numerator * other._denominator + this->_denominator * other._numerator;
        }
        return Fraction(num, don);
    }

    Fraction operator-(const Fraction& other)
    {
        int don = this->_denominator;
        int num = this->_numerator - other._numerator;
        if (this->_denominator != other._denominator)
        {
            don = this->_denominator * other._denominator;
            num = this->_numerator * other._denominator - this->_denominator * other._numerator;
        }
        return Fraction(num, don);
    }

    Fraction operator+(const Fraction& other)
    {
        int don = this->_denominator;
        int num = this->_numerator + other._numerator;

        return Fraction(num, don);
    }

    Fraction operator*(const Fraction& other)
    {
        int don = this->_denominator * other._denominator;
        int num = this->_numerator * other._numerator;

        return Fraction(num, don);
    }

    Fraction operator/(const Fraction& other)
    {
        int don = this->_denominator * other._numerator;
        int num = this->_numerator * other._denominator;
        return Fraction(num, don);
    }

    bool operator==(const Fraction& other)
    {
        int don = this->_denominator * other._denominator;
        int num = this->_denominator * other._numerator;
        this->_numerator = this->_numerator * other._denominator;
        if (this->_numerator == num)
            return true;

        else
            return false;
    }

    bool operator!=(const Fraction& other)
    {
        int don = this->_denominator * other._denominator;
        int num = this->_denominator * other._numerator;
        this->_numerator = this->_numerator * other._denominator;
        if (this->_numerator != num)
            return true;

        else
            return false;
    }

    Fraction operator=(const Fraction& other)
    {
        int don = this->_denominator * other._denominator;
        int num = this->_denominator * other._numerator;
        this->_numerator = this->_numerator * other._denominator;
        int num = this->_numerator;
        return Fraction(num, don);
    }

    bool operator!()
    {

        return !this->_numerator;
    }



    Fraction operator++()
    {

        _numerator += _denominator;

        return Fraction(_numerator, _denominator);
    }


    Fraction operator++()
    {
        Fraction cloned = (*this);
        _numerator += _denominator;
        return cloned;
    }

    Fraction operator--()
    {

        _numerator -= _denominator;
        int don = _denominator;
        int num = _numerator;
        return Fraction(num, don);
    }

    Fraction operator--()
    {
        Fraction cloned = (*this);
        _numerator -= _denominator;
        return cloned;
    }

    Fraction operator+=(int op)
    {
        while (op)
            _numerator += _denominator;

        return Fraction(_numerator, _denominator);
    }

    Fraction operator-=(int op)
    {
        while (op)
            _numerator -= _denominator;

        return Fraction(_numerator, _denominator);
    }

    Fraction operator*=(int op)
    {
        _numerator *= 3;
        return Fraction(_numerator, _denominator);

    }
    Fraction operator/=(int op)
    {
        _denominator *= 3;
        return Fraction(_numerator, _denominator);

    }
    Fraction operator^(int op)
    {
        while (op) {
            _denominator *= _denominator;
            _numerator *= _numerator;
        }
        return Fraction(_numerator, _denominator);
    }

    friend istream& operator>>(istream& input, Fraction& fraction) {
        cout << "Enter numerator: ";
        input >> fraction._numerator;

        cout << "Enter denominator: ";
        input >> fraction._denominator;

        return input;
    }

    friend ostream& operator<<(ostream& output, const Fraction& fraction) {
        output << fraction._numerator << '/' << fraction._denominator;
        return output;
    }

    operator double() const {
        double last_num = _numerator / _denominator;
        return last_num;
    }

    operator int() const {
        int last_num = _numerator / _denominator;
        return last_num;
    }

    operator char() const {
        char last_num = _numerator / _denominator;
        return last_num;
    }
    operator bool() const {
        if (_numerator == 0)
            return false;
        else
            return true;
    }
};