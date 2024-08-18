// Following is the solution for: https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

// Brute force
class Solution {
    // Function to find the leaders in the array.
  public:
    bool isMaxInSubArray(int arr[], int i, int n) {
        for (int x = i+1; x < n; x++) {
            if (arr[i] < arr[x]) return false;
        }
        return true;
    }
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> ans;
        for (int i = 0; i < n-1; i++) {
            if (isMaxInSubArray(arr, i, n)) {
                ans.push_back(arr[i]);
            }
        }
        ans.push_back(arr[n-1]);
        return ans;
    }
};

// Optimal
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> ans;
        ans.push_back(arr[n-1]);
        int maxSoFar = arr[n-1];
        for(int i = n-2; i >= 0; i--) {
            if (arr[i] >= maxSoFar) {
                ans.push_back(arr[i]);
                maxSoFar = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};