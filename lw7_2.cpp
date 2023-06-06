#include <iostream>

using namespace std;

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sum(n - 1);
}

int main()
{
    int n;
    cout << "Введите положительное число: ";
    cin >> n;
    cout << "Сумма первых " << n << " чисел = " << sum(n) << endl;
    return 0;
}
