// Following is the solution for: https://leetcode.com/problems/4sum/

// Brute (TC: ~O(n^4))
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;
        for (int i = 0; i <  n; i++) {
            for (int j = i+1; j <  n; j++) {
                for (int k = j+1; k <  n; k++) {
                    for (int l = k+1; l <  n; l++) {
                        long long sum = nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};

// Better
/*
Similar to 3 sum, just adapt it for 4 sum
*/

// Optimal
/*
Similar to 3 sum optimal, just instead of i only, i and j will be fixed and k and l will move.
*/