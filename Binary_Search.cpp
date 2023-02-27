#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int arr[], int l, int r, int key)
{
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] == key)
            return m;
        if (arr[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int binarySearchRec(int arr[], int l, int r, int key)
{
    if (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] == key)
            return m;
        if (arr[m] < key)
            binarySearchRec(arr, m + 1, r, key);
        else
            binarySearchRec(arr, l, m - 1, key);
    }
    return -1;
}
int main()
{
    int arr[] = {-10, 0, 20, 40, 50, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the value : ";
    cin >> key;
    int res = binarySearch(arr, 0, size - 1, key);
    if (res == -1)
    {
        cout << "the value (" << key << ") not found\n";
    }
    else
    {
        cout << "the value (" << key << ") found at position (" << res << ")\n";
    }
}
