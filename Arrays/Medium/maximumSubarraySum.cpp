// Following is the solution for: https://leetcode.com/problems/maximum-subarray/

// Brute force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j=i; j<nums.size(); j++) {
                sum += nums[j];
                maxsum = max(sum, maxsum);
            }
        }
        return maxsum;
    }
};

// Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxsum = nums[0];
        for (auto it: nums) {
            sum += it;
            maxsum = max(sum, maxsum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxsum;
    }
};