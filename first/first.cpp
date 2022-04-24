#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// сортировка методом простого выбора

void fillKeyboard(int n, int*& arr)
{
    cout << "Введенные элементы: ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
}

void fillRandom(int n, int*& arr)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand()%101;
    }
}

void outputArr(int n, int*& arr)
{
    cout << "Элементы массива: ";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1) cout << arr[i];
        else cout << arr[i] << " ";
    }
}

void selectionSort(int n, int*& arr)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_el = arr[i];
        int idx = i;
        for (int j=i; j < n; j++)
        {
            if (arr[j] < min_el)
            {
                min_el = arr[j];
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    time_t start, end;
    int n;
    cout << "Количество элементов в массиве: ";
    cin >> n;
    int* arr = new int[n];
    fillRandom(n, arr);
    //fillKeyboard(n, arr);
    outputArr(n, arr);
    cout << endl;
    selectionSort(n, arr);
    outputArr(n, arr);
    delete[] arr;
    return 0;
}
