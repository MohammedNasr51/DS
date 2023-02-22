#include <iostream>
#include <algorithm>
using namespace std;
void print(int arr[], int size) // to print array elements
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertion_sortasc(int arr[], int size) // to sort array ascending
{
    int key, j;                       // key is variable that we compare to shift or not , j is the index of previous element of the key
    for (size_t i = 1; i < size; i++) // start from 1 by assuming that the first element is sorted
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) // loop to shif elements
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void insertion_sortdesc(int arr[], int size) // to sort array descending
{
    int key, j;                       // key is variable that we compare to shift or not , j is the index of previous element of the key
    for (size_t i = 1; i < size; i++) // start from 1 by assuming that the first element is sorted
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key) // loop to shif elements
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {20, 50, 40, 90, 80, 70, -10, 100, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);
    insertion_sortasc(arr, size);
    print(arr, size);
    insertion_sortdesc(arr, size);
    print(arr, size);
}
// output is :

// 20 50 40 90 80 70 -10 100 0

// -10 0 20 40 50 70 80 90 100

// 100 90 80 70 50 40 20 0 -10
