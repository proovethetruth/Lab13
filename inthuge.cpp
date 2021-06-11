
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
    sign = a;
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
        c.sign = 1;
    else
    {
        c.sign = 0;
        c.numbers[c.size-1] = a - '0';
        i--;
    }

    for(; (a = s.get()) && i >= 0; i--)
        c.numbers[i] = a -'0';

    s.clear();
    s.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return s;
}

std::ostream& operator<<(std::ostream& s, const IntHuge& c) {
    if (c.numbers)
    {
        if (c.sign == 1)
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

IntHuge IntHuge::operator+ (const IntHuge& b) const
{
    int length = 0, error = 0;

    if (size > b.size)
        length = size + 1;
    else
        length = b.size + 1;
    
    IntHuge res(b, error);
    res.expand(length);

    for (int i = 0; i < length; i++)
    {
        res.numbers[i] += numbers[i]; // суммируем последние разряды чисел
        res.numbers[i + 1] += (res.numbers[i] / 10); // если есть разряд для переноса, переносим его в следующий разряд
        res.numbers[i] %= 10; // если есть разряд для переноса он отсекается
    }

    //if (res.numbers[length - 1] == 0)
    //    res.size--;
    std::cout << res;
    return res;
}