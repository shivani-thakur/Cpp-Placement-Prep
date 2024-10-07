// Following is the solution for: https://leetcode.com/problems/two-sum/

// Brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i]+nums[j] == target) return {i, j};
            }
        }
        return {-1, -1};
    }
};

// Better
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (m.find(rem) != m.end()) {
                return {m[rem], i};
            } else {
                m[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};

// Optimal
/*
In this case optimal is not very optimal, it takes same time complexity as the better. Space required is low. That's it.
1. Sort the array.
2. Keep 2 pointers. One at the left and other at the right.
3. Calculate sum.
4. If sum is greater than target, reduce right.
5. If sum is less than target, increase left.
6. Repeat till left is less than right.
For yes/no types question, this is a good solution. For index question Better solution is the best.
*/
