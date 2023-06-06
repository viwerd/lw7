#include <iostream>

using namespace std;

void printNum(int n)
{
    if (n == 1)
    {
        cout << n << endl;
        return; // Функция, которая ничего не возвращает
    }
    printNum(n - 1); // Ссылка, которая делает функцию рекурсивной
    cout << n << endl;
}

int main()
{
    setlocale(LC_ALL , "ru");
    int n;
    cout << "Введите положительное число: ";
    cin >> n;
    cout << "Вывод чисел от 1 до " << n << endl;
    printNum(n);
    return 0;
}
