// Following is the solution for: https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0

// Brute Force
/*
1. Generate all subarrays using nested loop.
2. Find minimum and second minimum from each subarray.
3. If it is greater than maximum sum, replace the maximum sum.
Time Complexity: O(N^3)
*/

// Optimal Solution
class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        int maxSum = INT_MIN, sum = 0;
        for (int i = 0; i < arr.size()-1; i++) {
            sum = arr[i] + arr[i+1];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};