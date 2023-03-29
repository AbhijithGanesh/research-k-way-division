#include <iostream>

using namespace std;

void printArray(int arr[])
{
    int size = sizeof(*arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "";
    }
    cout << endl;
}
