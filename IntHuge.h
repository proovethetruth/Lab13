#ifndef INT_HUGE_H
#define INT_HUGE_H

// Создайте класс IntHuge (длинные целые, представленные массивом разрядов)
// с операциями +, +=, -, -=, =, ==, !=, >, <, >=, <=, *, *=, *(int)
// (умножение на константу).
#include <iostream>

// 1 2 1 2 3 5 2 1 5 2
// "1212342152"

class IntHuge
{
private:
    int size;
    int* numbers;
    int sign;

public:
    IntHuge();
    IntHuge(int val, int& error);
    IntHuge(const IntHuge& f, int& error);
    ~IntHuge();

    int get_size() const;
    int get_sign() const;
    void set_sign(int sign);
    int get_num(int i, int& error) const;
    void set_num(int num, int i, int& error);

    friend std::istream& operator>> (std::istream& s, IntHuge& c);
    friend std::ostream& operator<< (std::ostream& s, const IntHuge& c);


    void expand(int length);
    //IntHuge operator+(const IntHuge&) const;
    //IntHuge operator-(const IntHuge&) const;
    //IntHuge operator*(double p) const;
    //void operator=(const IntHuge& f);

    IntHuge operator+(const IntHuge& b) const;
    IntHuge operator* (const int a) const;

    int operator==(const IntHuge& b) const;
    int operator<(const IntHuge& v) const;
    friend int operator !=(const IntHuge& a, const IntHuge& b);
    friend int operator <=(const IntHuge& a, const IntHuge& b);
    friend int operator >(const IntHuge& a, const IntHuge& b);
    friend int operator >=(const IntHuge& a, const IntHuge& b);

    const IntHuge operator -() const;
    const IntHuge operator +() const;
};

#endif