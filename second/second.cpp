#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// пирамидальная сортировка

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

void heapify(int n, int*& arr, int i)
{
    int max_el = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[max_el]) max_el = left;
    if (right < n && arr[right] > arr[max_el]) max_el = right;
    if (max_el != i)
    {
        int temp = arr[i];
        arr[i] = arr[max_el];
        arr[max_el] = temp;
        heapify(n, arr, max_el);
    }
}

void heapSort(int n, int*& arr)
{
    for (int i = n / 2 - 1; i >= 0; i--) heapify(n, arr, i);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(i, arr, 0);
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
    heapSort(n, arr);
    outputArr(n, arr);
    delete[] arr;
    return 0;
}
