
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

// Шаг 1. Считать строку
// Шаг 2. Посчитать её длину, выделить место
// Шаг 3. С помощью my_atoi(char*, int*) распарсить строку
// Шаг 4. Установить указатель туда, куда надо
// -89235
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

void IntHuge::expand(int length) {
    int* tmp = (int*)calloc(length, sizeof(double) * length);
    if (!tmp)
        return;

    if (numbers != NULL) {
        for (int i = 0; i < size; i++)
        {
            tmp[i] = numbers[i];
        }
        free(numbers);
        numbers = tmp;
        return;
    }
}

//IntHuge IntHuge::operator+ (const IntHuge& b) const
//{
//    int length = 0, error = 0;
//
//    if (size > b.size)
//        length = size + 1;
//    else
//        length = b.size + 1;
//    
//    IntHuge res(b, error);
//    res.expand(length);
//    
//    if (sign == 1 && b.sign == 1)
//        res.sign = 1;
//    if (sign == 1 || b.sign == 1)
//    {
//
//    }
//
//    for (int i = 0; i < length; i++)
//    {
//        res.numbers[i] += numbers[i]; // суммируем последние разряды чисел
//        res.numbers[i + 1] += (res.numbers[i] / 10); // если есть разряд для переноса, переносим его в следующий разряд
//        res.numbers[i] %= 10; // если есть разряд для переноса он отсекается
//    }
//
//    //if (res.numbers[length - 1] == 0)
//    //    res.size--;
//    std::cout << res;
//    return res;
//}

int IntHuge::operator==(const IntHuge& b) const {
    if ((size != b.size) || (sign != b.sign))
        return 0;
    else
    {
        for (int i = 0; i < size; i++)
        {
            if(numbers[i] != b.numbers[i])
                return 0;
        }
    }
    return 1;
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

const IntHuge IntHuge::operator -() const {
    IntHuge copy(*this);
    if (copy.sign == 1) copy.sign = -1;
    else copy.sign = 1;
    return copy;
}

const IntHuge IntHuge::operator +() const {
    return IntHuge(*this);
}

int operator !=(const IntHuge& a, const IntHuge& b) {
    return !(a == b);
}

int operator <=(const IntHuge& a, const IntHuge& b) {
    return (a < b || a == b);
}

int operator >(const IntHuge& a, const IntHuge& b) {
    return !(a <= b);
}

int operator >=(const IntHuge& a, const IntHuge& b) {
    return !(a < b);
}