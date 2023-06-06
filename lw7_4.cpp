#include <iostream>

using namespace std;

int sum(int n)
{
    if (n < 10)
    {
        return n;
    }
    return n % 10 + sum(n / 10);
}

int main()
{
    setlocale(LC_ALL , "ru");
    int n;
    cout << "Введите положительное число: ";
    cin >> n;
    cout << "Сумма цифр числа  " << n << " = " << sum(n) << endl;
    return 0;
}
