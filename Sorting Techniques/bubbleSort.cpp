// Following is the solution for: https://www.geeksforgeeks.org/problems/bubble-sort/1
#include <iostream>
#include <type_traits>
#include <utility>

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        // Your code here
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] >= arr[j+1]) {
                    std::swap(arr[j], arr[j+1]);
                }
            }
        }
    }
};