﻿#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
    {
        return a;
    }
    else {
        return gcd(b , a % b); // Если b равно нулю, то возвращается a (так как НОД любого числа и нуля равен этому числу).
    }                          // В противном случае функция вызывает саму себя с аргументами b и a % b (остаток от деления a на b) и возвращает результат.
}                              // Это продолжается до тех пор, пока b не будет равно нулю, после чего возвращается конечный результат.

/*  int gcd(int a, int b)
    {
        return !b ? a : gcd(b , a % b);
    }
*/

int main()
{
    setlocale(LC_ALL , "ru");
    int a , b;
    cout << "Введите два положительных числа через пробел: ";
    cin >> a >> b;
    cout << "НОК чисел " << a << " и " << b << " = " << a * b / gcd(a , b) << endl;
    return 0;
}
