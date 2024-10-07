// Following is the solution for: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// Brute Force
class Solution {
public:
    bool check(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            bool flag = true;
            for (int j = 0; j < nums.size()-1; j++) {
                int index = (i+j) % nums.size();
                if (nums[index] > nums[(index+1)%nums.size()]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};

// Other Solution
class Solution {
public:
    bool check(vector<int>& nums) {
        int numOfPairs = 0;
        for(int i = 0; i < nums.size(); i++) {
            int n = (i+1) % nums.size();
            if (nums[i] > nums[n]) {
                numOfPairs++;
            }
        }
        if (numOfPairs > 1) return false;
        return true;
    }
};