#include <iostream>

using namspace std;

void LIS(int arr[], int n, int &maxLIS, int &maxIndex) {
    // ���� ����� ������� ����� 1, �� ���������� ������������ ���������������������
    // ������� �� ������ �������� � ��� ������ ������� �������
    if (n == 1)
    {
        maxLIS = 1;
        maxIndex = 0;
        return;
    }
    // ����� ������� ������� ������� ����� ������ n-1. ��� ����� �����
    // ���������� ������������ ��������������������� ��� ������� �� ������� n-1
    // (�.�. ��� ���������� arr[0..n-2]).
    // ��� ����� �� ���������� �������� ������� findLIS ��� ������� ��������
    // � ������� �� n-1 � ������� ������ i, ��� �������� ����������
    // ������������ ��������������������� ����� ���������� �����
    int currentLIS = 1;
    int currentMaxIndex = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        int subLIS;
        int subMaxIndex;
        LIS(arr, i + 1, subLIS, subMaxIndex);
        if (arr[i] < arr[n - 1] && subLIS + 1 > currentLIS)
        {
            currentLIS = subLIS + 1;
            currentMaxIndex = i;
        }
    }
    // ������� ������� ���������� � ���������� ������������ ���������������������
    // ������ ���� �� ������ ����������� �������� � ����������� ����� ����������
    // ������������ ���������������������
    maxLIS = currentLIS;
    maxIndex = currentMaxIndex;
}

void printLIS(int arr[], int n)
{
    // ������� ���������� ������������ ��������������������� ��� ����� �������
    int maxLIS;
    int maxIndex;
    LIS(arr, n, maxLIS, maxIndex);
    // ���������� ������������ ��������������������� ����� �������� ������ �� ������
    // ��������, ���� ����� ������� ����� 1.
    if (maxLIS == 1)
    {
        cout << arr[maxIndex] << std::endl;
        return;
    }
    printLIS(arr, maxIndex + 1);
    cout << arr[n - 1] << std::endl;
}

int main()
{
    int arr[] = {3, 4, -1, 0, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printLIS(arr, n);
    return 0;
}
