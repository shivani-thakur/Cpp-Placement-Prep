// Following is the solution for: https://www.geeksforgeeks.org/problems/selection-sort/1

// Select the minimum from the array and place at the appropriate index
#include <climits>
class Solution
{
    public:
    int select(int arr[], int i,  int n)
    {
        // code here such that selectionSort() sorts arr[]
        int min = INT_MAX;
        int index = -1;
        for (int j = i; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
        return index;
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
        for (int i = 0; i < n; i++) {
           int j = select(arr, i, n);
           int temp = arr[i];
           arr[i] = arr[j];
           arr[j] = temp;
        }
    }
};