/*
Bubble Sort Algorithm

Problem Statement: Given an array of N integers, write a program to implement
the Bubble Sorting algorithm.

Examples

Example 1:
Input: N = 5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting we get 1,2,3,4,5

Example 2:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting we get 9,13,20,24,46,52

------------------------------------------------------------------
Brute Force
------------------------------------------------------------------
Approach:
Select the range of the unsorted array: Use an outer loop (i) that runs
backward from n-1 to 0 (where n is the size of the array). The value i = n-1
means the range is from 0 to n-1, i = n-2 means the range is from 0 to n-2,
and so on.
Push the maximum element to the end of the selected range: Use an inner loop
(j) that runs from 0 to i-1. Compare adjacent elements and swap them if
arr[j] > arr[j+1]. Repeating this process ensures the maximum element in the
current range moves to index i.
Progressively sort the array: After each outer loop iteration, the last part
of the array becomes sorted. For example:
After the first iteration, the element at the last index is sorted.
After the second iteration, the last two elements are sorted.
This continues until the entire array is sorted.
Complete sorting: After n-1 iterations, the whole array will be sorted.
Note: After each iteration, the sorted portion grows from the end, so the
last index of the unsorted range decreases by 1 (controlled by i). The inner
loop (j) ensures the maximum element in the range [0…i] is placed at index i.

Time Complexity: O(N^2), (where N = size of the array), for the worst, and
average cases.
Space Complexity: O(1).

------------------------------------------------------------------
Optimal Approach
------------------------------------------------------------------
The best case occurs if the given array is already sorted. We can reduce the
time complexity to O(N) by just adding a small check inside the loops.
We will check in the first iteration if any swap is taking place. If the
array is already sorted no swap will occur and we will break out from the
loops.
Thus the iteration of the outer loop will be just 1. And our overall time
complexity will be O(N).

Time Complexity: O(N^2) for the worst and average cases and O(N) for the
best case. Here, N = size of the array.
Space Complexity: O(1)
*/

/*
    Sample input.txt (order matters — matches the cin calls below):

    6                          -> n            (size of the array)
    13 46 24 52 20 9           -> arr[0..5]    (space or newline separated)
*/

#include <bits/stdc++.h>
using namespace std;

class BubbleSort
{
public:
    // Brute force version - always runs the full n-1 passes, no early exit.
    // Takes arr by value so it doesn't disturb the original array.
    void bubble_sort_brute(vector<int> arr)
    {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
        { // Use two nested loops to iterate over the array
            for (int j = 0; j <= i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]); // Swap arr[i] with arr[j+1]
                }
            }
        }
        cout << "After Using Bubble Sort (Brute Force):\n";
        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    // Optimal version - stops early once a full pass makes no swaps.
    void bubble_sort_optimal(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int didSwap = 0; // Use two nested loops to iterate over the array
            for (int j = 0; j <= i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]); // Swap arr[j+1] with arr[i]
                    didSwap = 1;
                }
            }
            if (didSwap == 0)
            {
                break;
            }
        }

        cout << "After Using Bubble Sort (Optimal):\n";
        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Before Using Bubble Sort:\n";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    BubbleSort sorter;
    sorter.bubble_sort_brute(arr);   // runs on a copy, just for demonstration
    sorter.bubble_sort_optimal(arr); // actually sorts arr in place

    return 0;
}