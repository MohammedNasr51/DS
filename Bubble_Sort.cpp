#include <iostream>
#include <algorithm>
using namespace std;
void Swap(int &x, int &y) // to swap tow elements
{
    int temp = x;
    x = y;
    y = temp;
}
void bubbleSortasc(int arr[], int size)
{
    bool flag = true; // to check if the array is sorted
    int count = 0;    // to count number of steps in all iterations
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(arr[j], arr[j + 1]);
                flag = false;
            }
            count++;
        }
        if (flag == true)
        {
            break;
        }
    }
    cout<<"number of steps : "<<count<<endl;
}
void bubbleSortdesc(int arr[], int size)
{
    bool flag = true; // to check if the array is sorted
    int count = 0;    // to count number of steps in all iterations
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                Swap(arr[j], arr[j + 1]);
                flag = false;
            }
            count++;
        }
        if (flag == true)
        {
            break;
        }
    }
    cout<<"number of steps : "<<count<<endl;
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
    bubbleSortasc(arr, size);
    print(arr, size);
    bubbleSortdesc(arr, size);
    print(arr, size);
}
// output is :  
// 20 50 40 90 80 70 -10 100 0 
// number of steps : 36
// -10 0 20 40 50 70 80 90 100
// number of steps : 36
// 100 90 80 70 50 40 20 0 -10
