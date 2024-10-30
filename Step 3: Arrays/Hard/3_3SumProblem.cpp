// Following is the solution for: https://leetcode.com/problems/3sum/

// Brute force (TC: ~O(n^3)*log(num. of unique triplets))
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        set<vector<int>> uniqueTriplets;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        uniqueTriplets.insert(temp);
                    }
                }
            }
        }
        ans.insert(ans.end(), uniqueTriplets.begin(), uniqueTriplets.end());
        return ans;
    }
};

// Better (TC: O(N^2)*logM)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> tempAns;
        for (int i = 0; i < n; i++) {
            set<int> setForK;
            for (int j = i+1; j < n; j++) {
                int k = -1 * (nums[i] + nums[j]);
                if (setForK.find(k) != setForK.end()) {
                    vector<int> v = {nums[i], nums[j], k};
                    sort(v.begin(), v.end());
                    tempAns.insert(v);
                }
                setForK.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(tempAns.begin(), tempAns.end());
        return ans;
    }
};

// Optimal (TC:~ O(nlogn) + O(n^2))
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];
                if (s < 0 ) {
                    j++;
                }
                else if (s > 0) {
                    k--;
                } 
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};