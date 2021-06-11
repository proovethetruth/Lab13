#include "IntHuge.h"
#include <iostream>
#include <string.h>

IntHuge::IntHuge()
{
    size = 0;
    numbers = NULL;
    sign = 0;
}

IntHuge::IntHuge(int val, int& error)
{
    size = 0;
    numbers = NULL;
    sign = 0;
    if (val < 0)
    {
        error = 1;
        return;
    }
    if (val > INT_MAX)
    {
        std::cout << " Input size is to big. Initial value was set to 40" << std::endl;
        size = 40;
    }

    size = val;
    numbers = (int*)calloc(size, sizeof(double) * (size));
}

IntHuge::IntHuge(const IntHuge& f, int& error)
{
    size = f.size;
    sign = f.sign;
    numbers = (int*)calloc(size, sizeof(double) * size);
    if (numbers == NULL) {
        error = -1;
        return;
    }

    for (int i = 0; i < size; i++)
        numbers[i] = f.numbers[i];
}

IntHuge::~IntHuge()
{
    if (numbers)
        delete[] numbers;
}

int IntHuge::get_size() const
{
    return size;
}

int IntHuge::get_sign() const
{
    return sign;
}

void IntHuge::set_sign(int a)
{
    if (a < 0)
        sign = -1;
    else
        sign = 1;
}

int IntHuge::get_num(int i, int& error) const
{
    if ((i >= 0) && (i < size) && numbers)
        return numbers[i];
    else
    {
        error = 1;
        return 1;
    }
}

void IntHuge::set_num(int num, int i, int& error) {
    if (!numbers || i < 0 || i >= size || num > INT_MAX || !num)
    {
        error = 1;
        return;
    }
    numbers[i] = num;
}

std::istream& operator>>(std::istream& s, IntHuge& c)
{
    int i = c.size - 1;
    char a = s.get();

    if (a == '-')
        c.sign = -1;
    else
    {
        c.sign = 1;
        c.numbers[i] = a - '0';
        i--;
    }
    for (; i >= 0 && (a = s.get()); i--)
    {
        if (a == '\n')
            a = s.get();
        while (a - '0' < 0)
        {
            s.clear();
            s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << " Incorrect Input.\n Try again, using positive integer numbers: ";
            if (c.sign == -1)
                std::cout << "-";
            for (int j = c.size - 1; j > i; j--)
                std::cout << c.numbers[j];
            a = s.get();
        }
        c.numbers[i] = a - '0';
    }


    s.clear();
    s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return s;
}

std::ostream& operator<<(std::ostream& s, const IntHuge& c) {
    if (c.numbers)
    {
        if (c.sign == -1)
            s << "-";
        for (int i = c.size - 1; i >= 0; i--)
            s << c.numbers[i];
    }
    return s;
}

//IntHuge& IntHuge::operator= (const IntHuge& b) {
//    ;
//}

//IntHuge IntHuge::operator+ (const IntHuge& b) const {
//    IntHuge res(*this);
//
//    if (res.sign == -1) {
//        if (b.sign == -1) return -(-res + (-b));
//        else return b - (-res);
//    }
//    else if (b.sign == -1) return res - (-b);
//    int carry = 0; // флаг переноса из предыдущего разряда
//    for (size_t i = 0; i < std::max(res.size, b.size) || carry != 0; ++i) {
//        if (i == res.size) res.set_num(res.size - 1);
//        left._digits[i] += carry + (i < right._digits.size() ? right._digits[i] : 0);
//        carry = left._digits[i] >= big_integer::BASE;
//        if (carry != 0) left._digits[i] -= big_integer::BASE;
//    }
//
//    return left;
//}
//
//IntHuge IntHuge::operator- (const IntHuge& b) {
//    IntHuge res(*this);
//    if (b.sign == -1) return res + (-b);
//    else if (res.sign == -1) return -(-res + b);
//    else if (res < b) return -(b - res);
//    int carry = 0;
//    for (size_t i = 0; i < b.size || carry != 0; ++i) {
//        res.numbers[i] -= carry + (i < b.size ? b.numbers[i] : 0);
//        carry = b.numbers[i] < 0;
//        if (carry != 0) res.numbers[i] += IntHuge::BASE;
//    }
//
//    res._remove_leading_zeros();
//    return left;
//}

/*------------------------------------------------------------------*/


int IntHuge::operator ==(const IntHuge& b) const {
    if ((size != b.size) || (sign != b.sign))
        return 0;
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (numbers[i] != b.numbers[i])
                return 0;
        }
    }
    return 1;
}

int operator !=(const IntHuge& a, const IntHuge& b) {
    return !(a == b);
}

int operator >(const IntHuge& a, const IntHuge& b) {
    return !(a <= b);
}

int IntHuge::operator<(const IntHuge& b) const {
    if (*this == b) return 0;
    if (sign == -1) {
        if (b.sign == -1) return ((-b) < (-*this));
        else return 1;
    }
    else if (b.sign == -1) return false;
    else {
        if (size != b.size) {
            return size < b.size;
        }
        else {
            for (long long i = size - 1; i >= 0; --i) {
                if (numbers[i] != b.numbers[i]) return numbers[i] < b.numbers[i];
            }
            return false;
        }
    }
}

int operator >=(const IntHuge& a, const IntHuge& b) {
    return !(a < b);
}

int operator <=(const IntHuge& a, const IntHuge& b) {
    return (a < b || a == b);
}

const IntHuge IntHuge::operator -() const {
    IntHuge copy(*this);
    if (copy.sign == 1) copy.sign = -1;
    else copy.sign = 1;
    return copy;
}

const IntHuge IntHuge::operator +() const {
    return IntHuge(*this);
}