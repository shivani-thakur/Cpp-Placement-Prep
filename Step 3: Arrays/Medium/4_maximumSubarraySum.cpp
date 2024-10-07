// Following is the solution for: https://leetcode.com/problems/maximum-subarray/

// Brute Force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};

// Optimal (Kadane's Algorithm), with follow question - print indices of the subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        int start = 0, end = -1, temp;
        for (int i = 0; i < nums.size(); i++) {
            if (sum == 0) temp = i;
            sum += nums[i];
            if (sum > maxSum) {
                maxSum = sum;
                start = temp;
                end = i;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        cout << start << " " << end;
        return maxSum;
    }
};