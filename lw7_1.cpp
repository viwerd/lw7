#include <iostream>

using namespace std;

void printNum(int n)
{
    if (n == 1)
    {
        cout << n << endl;
        return; // �������, ������� ������ �� ����������
    }
    printNum(n - 1); // ������, ������� ������ ������� �����������
    cout << n << endl;
}

int main()
{
    setlocale(LC_ALL , "ru");
    int n;
    cout << "������� ������������� �����: ";
    cin >> n;
    cout << "����� ����� �� 1 �� " << n << endl;
    printNum(n);
    return 0;
}
