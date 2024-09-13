#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);
int MoFind(int arr[], int n);
float MdFind(int arr[], int n);
float ArithmeticAverage(int arr[], int n);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    const int N = 30;
    const int MAX_VALUE = 22;
    int arr[N]{};
    
    for (int i = 0; i < N; i++) {
        arr[i] = 1 + rand() % MAX_VALUE;
       
    }

    cout << "Генерація випадкових чисел: " << endl;
    printArray(arr, N);

    insertionSort(arr, N);
    cout << "\nСортування ряду:  " << endl;
    printArray(arr, N);

    cout << "\nСереднє арифметичне: " << ArithmeticAverage(arr, N)<<endl;

    cout << "\nМедіана: : " << MdFind(arr, N) << endl;

    cout << "\nМода: : " << MoFind(arr, N) << endl;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

float ArithmeticAverage(int arr[], int n) 
{
    int summ = 0;
    for (int i = 0; i < n; ++i)
        summ += arr[i];
    return static_cast<float>(summ) / n;
}

float MdFind(int arr[], int n) 
{
    float median;
    if (n % 2 == 0) {
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else {
        median = arr[n / 2];
    }
    return median;
}

int MoFind(int arr[], int n)
{
    int mode = -1;
    int curr_count = 1;
    int max_count = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            ++curr_count;
        }
        else {
            if (curr_count > max_count) {
                max_count = curr_count;
                mode = arr[i - 1];
            }
            curr_count = 1;  
        }
    }
    if (curr_count > max_count) {
        mode = arr[n - 1];
    }   

    return mode;
}