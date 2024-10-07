// Following is the solution for: https://leetcode.com/problems/rearrange-array-elements-by-sign/

// This is the only possible solution. No trick to optimize it further.
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> merged(nums.size());
        int posIndex = 0, negIndex = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                merged[negIndex] = nums[i];
                negIndex += 2;
            } else {
                merged[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return merged;
    }
};