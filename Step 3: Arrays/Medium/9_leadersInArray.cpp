// Following is the solution for: https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

// Brute Force
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool led = true;
            for (int j = i+1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    led = false;
                    break;
                }
            }
            if(led) {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};

// Optimal Solution (Starting at the end, keep track of max element and check if current element is greater than max element)
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> ans;
        int maxEle = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] >= maxEle) {
                ans.push_back(arr[i]);
                maxEle = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};