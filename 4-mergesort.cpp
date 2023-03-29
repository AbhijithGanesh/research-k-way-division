#include <iostream>
#include "utils.cpp"
#include <chrono>
using namespace std;

void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{

    if (l < r)
    {
        int m1 = l + (r - l) / 4;
        int m2 = l + 2 * (r - l) / 4;
        int m3 = l + 3 * (r - l) / 4;

        mergeSort(arr, l, m1);
        mergeSort(arr, m1 + 1, m2);
        mergeSort(arr, m2 + 1, m3);
        mergeSort(arr, m3 + 1, r);
        merge(arr, l, m1, m2);
        merge(arr, m2 + 1, m3, r);
        merge(arr, l, m2, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The array before sorting is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    auto st1 = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto st2 = chrono::high_resolution_clock::now();

    auto t1 = chrono::duration_cast<std::chrono::nanoseconds>(st2 - st1);

    cout << "The array before sorting is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The array after sorting is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The time taken by the mergesort algorithm is nanoseconds " << t1.count() << endl;
    return 0;
}