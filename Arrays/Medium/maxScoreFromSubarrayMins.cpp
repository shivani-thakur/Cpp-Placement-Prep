// Following is the solution for: https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0

// Brute force
class Solution {
  public:
    pair<int, int> getElems(vector<int> &arr,int i, int j) {
        int max = arr[i], secMax = INT_MAX;
        for (int x=i+1; x <= j; x++) {
            if(arr[x] < max) {
                secMax = max;
                max = arr[x];
            } else if (arr[x] < secMax) {
                secMax = arr[x];
            }
        }
        return {max, secMax};
    }
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int maxSum = 0;
        int n = arr.size();
        for(int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                pair<int, int> p = getElems(arr, i, j);
                if (maxSum < (p.first + p.second)) {
                    maxSum = p.first + p.second;
                }
            }
        }
        return maxSum;
    }
};

