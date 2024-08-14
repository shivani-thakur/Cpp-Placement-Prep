// Following is the solution for: https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>

// Brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        pair<int,int> p;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Using Hashing
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (m.find(rem) != m.end()) {
                return {m[rem], i};
            } else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};

// Solution 3: 2 pointer approach. Put one ptr at the start and other at the end. if sum of these numbers is less than target then increament i. else decreament j.