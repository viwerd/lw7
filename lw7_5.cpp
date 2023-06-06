#include <iostream>

using namspace std;

void LIS(int arr[], int n, int &maxLIS, int &maxIndex) {
    // Если длина массива равна 1, то наибольшая возрастающая подпоследовательность
    // состоит из одного элемента и это первый элемент массива
    if (n == 1)
    {
        maxLIS = 1;
        maxIndex = 0;
        return;
    }
    // Пусть текущий элемент массива имеет индекс n-1. Нам нужно найти
    // наибольшую возрастающую подпоследовательность для массива до индекса n-1
    // (т.е. для подмассива arr[0..n-2]).
    // Для этого мы рекурсивно вызываем функцию findLIS для каждого элемента
    // в массиве до n-1 и находим индекс i, для которого наибольшая
    // возрастающая подпоследовательность имеет наибольшую длину
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
    // Текущий элемент включается в наибольшую возрастающую подпоследовательность
    // только если он больше предыдущего элемента и увеличивает длину наибольшей
    // возрастающей подпоследовательности
    maxLIS = currentLIS;
    maxIndex = currentMaxIndex;
}

void printLIS(int arr[], int n)
{
    // Находим наибольшую возрастающую подпоследовательность для всего массива
    int maxLIS;
    int maxIndex;
    LIS(arr, n, maxLIS, maxIndex);
    // Наибольшая возрастающая подпоследовательность может состоять только из одного
    // элемента, если длина массива равна 1.
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
