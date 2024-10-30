// Following is the solution for: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

// Brute
/*
Generate all subarrays using nested loop and check if sum is equal to 0
*/

// Better
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        map<int, int> m;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == 0) {
                ans = max(ans, i+1);
            }
            if (m.find(sum) != m.end()) {
                ans = max(ans, i - m[sum]);
            }
            else {
                m[sum] = i;
            }
        }
        return ans;
    }
};