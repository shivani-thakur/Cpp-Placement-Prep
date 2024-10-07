// Following is the solution for: https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxcnt = 0;
        for (auto it: nums) {
            if (it == 1) {
                cnt++;
                maxcnt = max(maxcnt, cnt);
            } else {
                cnt = 0;
            }
        }
        return maxcnt;
    }
};