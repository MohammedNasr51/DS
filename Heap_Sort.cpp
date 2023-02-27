#include <iostream>
#include <algorithm>
using namespace std;
void heapify(int arr[], int size, int i) // to check that the heapis max heap
{
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;
    int max = i;
    if (left < size && arr[left] > arr[max])
        max = left;
    if (right < size && arr[right] > arr[max])
        max = right;
    if (max != i)
    {
        swap(arr[max], arr[i]);
        heapify(arr, size, max);
    }
}
void buildHeap(int arr[], int size) // to arrange the array as a heap
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}
void heapSort(int arr[], int size) // to sort array ascending
{
    buildHeap(arr, size);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void print(int arr[], int size) // to print array elements
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {20, 50, 40, 90, 80, 70, -10, 100, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size); // befor sorting
    heapSort(arr, size);
    print(arr, size); // after sorting
}
