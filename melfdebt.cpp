// melfdebt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class Rational {
public:
    Rational(int num,int denom)
        :numerator{ num },
        denominator{ denom }
    {

    }

    void print() {
        cout << numerator << "/" << denominator << endl;
    }

    Rational operator/(const Rational& other) {
        Rational rat(this->numerator * other.denominator, this->denominator * other.numerator);
        rat = evklid(rat);
        return rat;
    }
    Rational operator+(const Rational& other) {
        Rational result{ *this };
        Rational r1{ *this };
        Rational r2{ other };
        if (this->denominator != other.denominator) {
            result.denominator = this->denominator * other.denominator;
            r2.numerator *= this->denominator;
            r1.numerator *= other.denominator;
        }
        else result.denominator = this->denominator;
        result.numerator = r1.numerator + r2.numerator;
        result = evklid(result);
        return result;
    }
    Rational operator-(const Rational& other) {
        Rational result{ *this };
        Rational r1{ *this };
        Rational r2{ other };
        if (this->denominator != other.denominator) {
            result.denominator = this->denominator * other.denominator;
            r2.numerator *= this->denominator;
            r1.numerator *= other.denominator;
        }
        else result.denominator = this->denominator;
        result.numerator = r1.numerator - r2.numerator;
        result = evklid(result);
        return result;
    }
    Rational operator*(const Rational& other) {
        Rational rat(this->numerator * other.numerator, this->denominator * other.denominator);
        rat = evklid(rat);
        return rat;
    }
    Rational evklid(Rational& rat) {
        Rational r1{ rat };
        int nod{};
        while (r1.denominator != 0 and r1.numerator != 0) {
            if (r1.denominator > r1.numerator) {
                r1.denominator %= r1.numerator;
            }
            else {
                r1.numerator%= r1.denominator;
            }
        }
        nod=(r1.denominator + r1.numerator);
        rat.numerator /= nod;
        rat.denominator /= nod;
        return rat;
    }
private:
    int numerator{};
    int denominator{};
};

int main()
{
    Rational rat1(3, 6);
    Rational rat2(4, 7);
    Rational rat3 = rat1 / rat2;
    rat3.print();
}
