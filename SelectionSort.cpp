#include <iostream>
#include <algorithm>
using namespace std;
void Swap(int &x, int &y) // to swap tow elements
{
    int temp = x;
    x = y;
    y = temp;
}
void SelectionSortasc(int arr[], int size) // to sort array ascending
{
    int minidx;
    for (int i = 0; i < size - 1; i++)
    {
        minidx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minidx])
                minidx = j;
            Swap(arr[minidx], arr[i]);
        }
    }
}
void SelectionSortdesc(int arr[], int size) // to sort array descending
{
    int minidx;
    for (int i = 0; i < size - 1; i++)
    {
        minidx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[minidx])
                minidx = j;
            Swap(arr[minidx], arr[i]);
        }
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
    print(arr, size);
    SelectionSortasc(arr, size);
    print(arr, size);
    SelectionSortdesc(arr, size);
    print(arr, size);
}
