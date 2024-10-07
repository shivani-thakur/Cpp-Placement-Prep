// Following is the solution for: https://www.geeksforgeeks.org/problems/merge-sort/1

#include <vector>

class Solution
{
    public:
    // Merges two sorted halves of the array into a single sorted segment
    void merge(int arr[], int l, int m, int r)
    {
        // Create a temporary vector to store the merged sorted elements
        vector<int> v;

        // Initialize pointers to the start of each half
        int i1 = l;        // Start of the left half
        int i2 = m + 1;    // Start of the right half

        // Compare elements from both halves and merge them in sorted order
        while (i1 <= m && i2 <= r) {
            if (arr[i1] < arr[i2]) {
                v.push_back(arr[i1]); // Push element from left half if smaller
                i1++; // Move pointer in the left half forward
            }
            else if (arr[i1] > arr[i2]) {
                v.push_back(arr[i2]); // Push element from right half if smaller
                i2++; // Move pointer in the right half forward
            }
            else {
                // If elements are equal, push both to maintain stability
                v.push_back(arr[i1]);
                v.push_back(arr[i2]);
                i1++; // Move both pointers forward
                i2++;
            }
        }

        // If there are remaining elements in the left half, add them to the vector
        while (i1 <= m) {
            v.push_back(arr[i1]);
            i1++;
        }

        // If there are remaining elements in the right half, add them to the vector
        while (i2 <= r) {
            v.push_back(arr[i2]);
            i2++;
        }

        // Copy the merged elements back into the original array
        int i = l;
        for (auto it : v) {
            arr[i] = it;
            i++;
        }
    }

    public:
    // Recursively divides the array into two halves and merges them back in sorted order
    void mergeSort(int arr[], int l, int r)
    {
        // Base case: if the array has one or zero elements, it's already sorted
        if (l >= r) return;

        // Find the middle point to divide the array into two halves
        int mid = (l + r) / 2;

        // Recursively sort the left half
        mergeSort(arr, l, mid);

        // Recursively sort the right half
        mergeSort(arr, mid + 1, r);

        // Merge the two sorted halves
        merge(arr, l, mid, r);
    }
};
