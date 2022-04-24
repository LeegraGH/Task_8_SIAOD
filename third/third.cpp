#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// cортировка подсчетом

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

void countSort(int n, int*& arr)
{
    int temp_arr [101] = {};
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        temp_arr[arr[i]]++;
    }
    for (int i = 0; i < 101; i++)
    {
        if (temp_arr[i] != 0)
        {
            int k = temp_arr[i];
            while (k != 0)
            {
                arr[j] = i;
                j++;
                k--;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int n;
    cout << "Количество элементов в массиве: ";
    cin >> n;
    int* arr = new int[n];
    fillRandom(n, arr);
    //fillKeyboard(n, arr);
    outputArr(n, arr);
    cout << endl;
    countSort(n, arr);
    outputArr(n, arr);
    delete[] arr;
    return 0;
}
