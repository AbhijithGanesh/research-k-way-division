#include <vector>
#include <queue>

using namespace std;

vector<int> mergeKSortedArray(vector<vector<int>> &arr)
{
    // Initialize a min heap to store the smallest element from each array
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Insert the first element from each array into the heap
    for (int i = 0; i < arr.size(); i++)
    {
        if (!arr[i].empty())
        {
            pq.push({arr[i][0], i});
        }
    }

    vector<int> res;
    while (!pq.empty())
    {
        // Pop the smallest element from the heap
        pair<int, int> cur = pq.top();
        pq.pop();

        // Add the smallest element to the result vector
        res.push_back(cur.first);

        // If the array from which the smallest element was taken still has elements
        // remaining, insert the next smallest element from that array into the heap
        int row = cur.second;
        if (arr[row].size() > 1)
        {
            arr[row].erase(arr[row].begin());
            pq.push({arr[row][0], row});
        }
    }

    return res;
}
