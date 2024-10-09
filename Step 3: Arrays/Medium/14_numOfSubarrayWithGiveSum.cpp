// Following is the solution for: https://leetcode.com/problems/subarray-sum-equals-k/

// Brute Force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) ans++;
            }
        }
        return ans;
    }
};

// Optimal (Using Map)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0] = 1;
        int prefix = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int rem = prefix - k;
            if (m.find(rem) != m.end()) {
                ans += m[rem];
            }
            m[prefix]++;
        }
        return ans;
    }
};