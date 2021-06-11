#ifndef INT_HUGE_H
#define INT_HUGE_H

#include <iostream>

class IntHuge
{
private:
    int size;
    int capacity;
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


    /*----------------------------------------------------------*/

    // IntHuge& operator =(const IntHuge& b);
    // friend const IntHuge operator +(const IntHuge& a, const IntHuge& b);

    /*----------------------------------------------------------*/

    int operator ==(const IntHuge& b) const;
    int operator <(const IntHuge& b) const;
    friend int operator !=(const IntHuge& a, const IntHuge& b);
    friend int operator <=(const IntHuge& a, const IntHuge& b);
    friend int operator >(const IntHuge& a, const IntHuge& b);
    friend int operator >=(const IntHuge& a, const IntHuge& b);

    const IntHuge operator -() const;
    const IntHuge operator +() const;
};

#endif