// Following is the solution for: https://leetcode.com/problems/majority-element-ii/

// Brute Force
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int mini = n/3;
        for (int i = 0; i < n; i++) {
            if (ans.size() == 0 || ans[0] != nums[i]) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (nums[j] == nums[i]) cnt++;
                }
                if (cnt > mini) ans.push_back(nums[i]);
            }
            if (ans.size() == 2) return ans;
        }
        return ans;
    }
};

// Better (Using hash map)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int, int> m;
        int n =  nums.size();
        int mini = n/3;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
            if (m[nums[i]] == mini+1) ans.push_back(nums[i]);
        }
        return ans;
    }
};

// Optimal (Constant space using boyer moore voting algorithm)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
        for (auto it: nums) {
            if (cnt1 == 0 && el2 != it) {
                cnt1 = 1;
                el1 = it;
            }
            else if (cnt2 == 0 && el1 != it) {
                cnt2 = 1;
                el2 = it;
            }
            else if(el1 == it) cnt1++;
            else if(el2 == it) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (auto it: nums) {
            if (it == el1) cnt1++;
            if (it == el2) cnt2++;
        }
        vector<int> ans;
        if (cnt1 > (nums.size()/3)) ans.push_back(el1);
        if (cnt2 > (nums.size()/3)) ans.push_back(el2);

        return ans;
    }
};
