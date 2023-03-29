#include <iostream>
#include <bits/stdc++.h>
#include "utils.cpp"
#include <chrono>
using namespace std;

void insertion_sort(int arr[], int start, int end)
{
    for (int j = start; j < end; j++)
    {
        int key = arr[j];
        int i = j - 1;
        while ((i >= 0) && (arr[i] > key))
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}
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

// void merge(int arr[], int start, int div_1, int div_2, int end)
// {
//
//     int size_1 = (div_1 - start);
//     int size_2 = (div_2 - div_1);
//     int size_3 = (end - div_2);
//
//     int arr_1[size_1],
//         arr_2[size_2],
//         arr_3[size_3];
//
//     for (int i = 0; i < size_1; i++)
//         arr_1[i] = arr[start + i];
//     for (int j = 0; j < size_2; j++)
//         arr_2[j] = arr[div_1 + j + 1];
//     for (int k = 0; k < size_3; k++)
//         arr_3[k] = arr[div_2 + k + 1];
//
//     int iter_1 = 0;
//     int iter_2 = 0;
//     int iter_3 = 0;
//     int parent_iter = start;

//     while (iter_1 < size_1 && iter_2 < size_2 && iter_3 < size_3)
//     {
//         if (arr_1[iter_1] <= arr_2[iter_2] && arr_1[iter_1] <= arr_3[iter_3])
//         {
//             arr[parent_iter] = arr_1[iter_1];
//             iter_1++;
//         }
//         else if (arr_2[iter_2] <= arr_3[iter_3] && arr_2[iter_2] <= arr_1[iter_1])
//         {
//             arr[parent_iter] = arr_2[iter_2];
//             iter_2++;
//         }
//         else if (arr_3[iter_3] <= arr_1[iter_1] && arr_3[iter_3] <= arr_2[iter_2])
//         {
//             arr[parent_iter] = arr_3[iter_3];
//             iter_3++;
//         }
//         parent_iter++;
//     }

//     while (iter_1 < size_1 && iter_2 < size_2)
//     {
//         if (arr_1[iter_1] <= arr_2[iter_2])
//         {
//             arr[parent_iter] = arr_1[iter_1];
//             iter_1++;
//         }
//         else if (arr_1[iter_1] > arr_2[iter_2])
//         {
//             arr[parent_iter] = arr_2[iter_2];
//             iter_2++;
//         }
//         parent_iter++;
//     }
//     while (iter_2 < size_2 && iter_3 < size_3)
//     {
//         if (arr_2[iter_2] <= arr_3[iter_3])
//         {
//             arr[parent_iter] = arr_2[iter_2];
//             iter_2++;
//         }
//         else if (arr_2[iter_2] > arr_3[iter_3])
//         {
//             arr[parent_iter] = arr_3[iter_3];
//             iter_3++;
//         }
//         parent_iter++;
//     }
//     while (iter_3 < size_3 && iter_1 < size_1)
//     {
//         if (arr_3[iter_3] <= arr_1[iter_1])
//         {
//             arr[parent_iter] = arr_3[iter_3];
//             iter_3++;
//         }
//         else if (arr_1[iter_1] < arr_3[iter_3])
//         {
//             arr[parent_iter] = arr_1[iter_1];
//             iter_1++;
//         }
//         parent_iter++;
//     }
//
//     while (iter_1 < size_1)
//     {
//         arr[parent_iter] = arr_1[iter_1];
//         iter_1++;
//         parent_iter++;
//     }

//     while (iter_2 < size_2)
//     {
//         arr[parent_iter] = arr_2[iter_2];
//         iter_2++;
//         parent_iter++;
//     }

//     while (iter_3 < size_3)
//     {
//         arr[parent_iter] = arr_2[iter_2];
//         iter_3++;
//         parent_iter++;
//     }
// }

void mergeSort(int arr[], int start, int end)
{
    if (end > start)
    {
        int div_1 = start + (end - start) / 3; // (8-0/3) = 2. This should be changed to 3 due to index concerns while merging
        int div_2 = start + 2 * (end - start) / 3;
        mergeSort(arr, start, div_1);
        mergeSort(arr, div_1 + 1, div_2);
        mergeSort(arr, div_2 + 1, end);
        merge(arr, start, div_1, div_2); // Merges 1 and 2.
        merge(arr, start, div_2, end);
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

    auto time = chrono::duration_cast<std::chrono::nanoseconds>(st2 - st1);

    cout << endl;

    cout << "The array after sorting is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The time taken by the 3-split mergesort algorithm is nanoseconds " << time.count() << endl;
    // cout << "Percentage difference " << 100 * (t1.count() - t2.count()) / t1.count() << endl;
    return 0;
}