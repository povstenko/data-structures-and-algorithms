#include <iostream>
#include <time.h>
#include <ctime>
#define N 100 * 10
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

unsigned int selectionSort(int arr[])
{
    unsigned int start_time = clock();
    int k, x;
    for (int i = 0; i < N; i++) {
        k = i;
        x = arr[i];
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < x) {
                k = j;
                x = arr[j];
            }
        }
        arr[k] = arr[i];
        arr[i] = x;
    }
    return clock() - start_time;
}

unsigned int insertionSort(int arr[])
{
    unsigned int start_time = clock();
    for (int i = 1; i < N; i++) {
        int x = arr[i];
        int j = i - 1;
        for (; j > -1 && arr[j] > x; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = x;
    }
    return clock() - start_time;
}

unsigned int bubbleSort(int arr[])
{
    unsigned int start_time = clock();
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i - 1; j--) {
            if (arr[j] < arr[j - 1]) {
                int buf = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = buf;
            }
        }
    }
    return clock() - start_time;
}

void shakerSort(int arr[], int n)
{
    int j, k = n - 1;
    int lb = 1, ub = n - 1;
    int x;
    cout << endl;
    do {
        print(arr, n);
        for (j = ub; j > 0; j--) {
            if (arr[j - 1] > arr[j]) {
                x = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = x;
                k = j;
            }
        }
        lb = k + 1;
        for (j = 1; j <= ub; j++) {
            if (arr[j - 1] > arr[j]) {
                x = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = x;
                k = j;
            }
        }
        ub = k - 1;
    } while (lb < ub);
    print(arr, n);
}

unsigned int shakerSort(int arr[])
{
    unsigned int start_time = clock();
    int j, k = N - 1;
    int lb = 1, ub = N - 1;
    int x;
    do {
        for (j = ub; j > 0; j--) {
            if (arr[j - 1] > arr[j]) {
                x = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = x;
                k = j;
            }
        }
        lb = k + 1;
        for (j = 1; j <= ub; j++) {
            if (arr[j - 1] > arr[j]) {
                x = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = x;
                k = j;
            }
        }
        ub = k - 1;
    } while (lb < ub);
    return clock() - start_time;
}

void randomizeArr(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (20 * 10) + 1;
    }
}

int main()
{
    cout << "Task N1\n\n";

    int arr[10];
    srand(time(NULL));

    randomizeArr(arr, 10);

    cout << "shaker sort:" << endl;
    shakerSort(arr, 10);

    cout << "\nTask N2\n\n";
    int s[N], tmp[N];

    cout << "N = " << N << endl;
    randomizeArr(s, N);
    copy(s, s + N, tmp);

    cout << "Selection sort time: " << selectionSort(s) << endl;
    copy(tmp, tmp + N, s);
    cout << "bubble sort time: " << bubbleSort(s) << endl;
    copy(tmp, tmp + N, s);
    cout << "insertion sort time:" << insertionSort(s) << endl;
    copy(tmp, tmp + N, s);
    cout << "shaker sort time: " << shakerSort(s) << endl;
}