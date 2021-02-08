#include <iostream>
#include <time.h>
using namespace std;
#define N 10

void print(int arr[])
{
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void randomizer(int arr[])
{
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 10;
    }
}

void selectionSort(int arr[])
{
    long i, j, k;
    int x;
    for (i = 0; i < N; i++) {
        print(arr);
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
}

void insertionSort(int arr[])
{
    for (int i = 1; i < N; i++) {
        print(arr);
        int x = arr[i];
        int j = i - 1;
        for (; j > -1 && arr[j] > x; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = x;
    }
    print(arr);
}

void bubbleSort(int arr[])
{
    for (int i = 0; i < N; i++) {
        print(arr);
        for (int j = N - 1; j > i - 1; j--) {
            if (arr[j] < arr[j - 1]) {
                int buf = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = buf;
            }
        }
    }
}

void insertionSortDesc(int arr[])
{
    for (int i = 1; i < N; i++) {
        int x = arr[i];
        int j = i - 1;
        for (; j > -1 && arr[j] < x; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = x;
    }
}




int main()
{
    cout << "Task N1\n\n";

    int s[N];
    srand(time(NULL));

    randomizer(s);
    cout << "selection sort:" << endl;
    selectionSort(s);

    randomizer(s);
    cout << "insertion sort" << endl;
    insertionSort(s);

    randomizer(s);
    cout << "bubble sort:" << endl;
    bubbleSort(s);

    cout << "Task N2\n\n";
    int matrix[N][N];

    cout << "matrix:" << endl;
    for (int i = 0; i < N; i++) {
        randomizer(matrix[i]);
        print(matrix[i]);
    }
    cout << "sorted matrix:" << endl;
    for (int i = 0; i < N; i++) {
        insertionSortDesc(matrix[i]);
        print(matrix[i]);
    }
}