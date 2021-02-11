#include <bits/stdc++.h>
using namespace std;

// function to merge in increasing order
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // creating left and right arrays:
    int L[n1], R[n2];

    // copying the data to temporary arrays:
    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = low;

    // merging both the Left and Right arrays:
    while (i < n1 && j < n2)
    {
        if (L[i] > R[j]) // change equality sign for decreasing order
        {
            arr[k] = R[j];
            j++;
        }
        else
        {
            arr[k] = L[i];
            i++;
        }
        k++;
    }

    // now copying the remaining elements if any,
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

// function to perform merge sort
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);      // sorting left half of the array
    mergeSort(arr, mid + 1, high); // sorting right half of the array
    merge(arr, low, mid, high);    // merging both the sub arrays
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {13, 15, 3, 1, 6, 9, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Sorting: " << endl;
    display(arr, size);
    mergeSort(arr, 0, size - 1);
    cout << "After Sorting: " << endl;
    display(arr, size);
    return 0;
}
