#include <iostream>
#include <algorithm>
using namespace std;
void print(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition1(int arr[], int start, int end)
{
    int i = start, j = end;
    int povitloc = start;
    while (true)
    {
        while (arr[povitloc] <= arr[j] && povitloc != j)
        {
            j--;
        }
        if (povitloc == j)
        {
            break;
        }
        else if (arr[povitloc] > arr[j])
        {
            swap(arr[povitloc], arr[j]);
            povitloc = j;
        }
        while (arr[povitloc] >= arr[i] && povitloc != i)
        {
            i++;
        }
        if (povitloc == i)
        {
            break;
        }
        else if (arr[povitloc] <= arr[i])
        {
            swap(arr[povitloc], arr[i]);
            povitloc = i;
        }
    }

    return povitloc;
}
int partition2(int arr[], int start, int end)
{
    int i = start, j = end, povitloc = start;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= arr[povitloc]);
        do
        {
            j--;
        } while (arr[j] > arr[povitloc]);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[povitloc], arr[j]);
    return j;
}
void QuickSort1(int arr[], int start, int end)
{
    if (start < end)
    {
        int piv = partition1(arr, start, end);
        QuickSort1(arr, start, piv - 1);
        QuickSort1(arr, piv + 1, end);
    }
}
void QuickSort2(int arr[], int start, int end)
{
    if (start < end)
    {
        int piv = partition2(arr, start, end);
        QuickSort2(arr, start, piv - 1);
        QuickSort2(arr, piv + 1, end);
    }
}
int main()
{
    int arr[] = {20, 50, 40, 90, 80, 70, -10, 100, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);
    QuickSort1(arr, 0, size - 1);
    print(arr, size);
    QuickSort2(arr, 0, size - 1);
    print(arr, size);
}
// output is :

// 20 50 40 90 80 70 -10 100 0

// -10 0 20 40 50 70 80 90 100

// -10 0 20 40 50 70 80 90 100
