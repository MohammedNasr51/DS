#include <iostream>
using namespace std;
void print(int arr[], int size) // to print array elements
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void merge_desc(int arr[], int l, int m, int r) // m=(l+(r-l))/2
{
    int i, j, k;                            // one to the first sub array and the second to the second one but the third is to the merged array
    int n1 = m - l - 1;                     // size of the first sub array
    int n2 = r - m;                         // size of the second sub array
    int *L = new int[n1], *R = new int[n2]; // sub arrays
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_asc(int arr[], int l, int m, int r) // m=(l+(r-l))/2
{
    int i, j, k;                            // one to the first sub array and the second to the second one but the third is to the merged array
    int n1 = m - l - 1;                     // size of the first sub array
    int n2 = r - m;                         // size of the second sub array
    int *L = new int[n1], *R = new int[n2]; // sub arrays
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int l, int r, string sortType)
{
    if (l < r)
    {
        int m = (l + (r - l)) / 2;
        merge_sort(arr, l, m, sortType);
        merge_sort(arr, m + 1, r, sortType);
        if (sortType == "asc")
        {
            merge_asc(arr, l, m, r);
        }
        else if (sortType == "desc")
        {
            merge_desc(arr, l, m, r);
        }
        else
        {
            merge_asc(arr, l, m, r);
        }
    }
}
int main()
{
    int arr[] = {20, 50, 40, 90, 80, 70, -10, 100, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr, size);
    merge_sort(arr, 0, size - 1, "asc");
    print(arr, size);
    merge_sort(arr, 0, size - 1, "desc");
    print(arr, size);
}
