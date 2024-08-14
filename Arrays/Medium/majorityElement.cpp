// Following is the solution for: https://leetcode.com/problems/majority-element/description/

// Brute Force
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int cond = len / 2;
        for (int i = 0; i < len; i++) {
            int cnt = 0;
            for (int j = 0; j < len; j++) {
                if (nums[i] == nums[j]) {
                    cnt++;
                }
            }
            if (cnt > cond) return nums[i];
        }
        return -1;
    }
};

// Using hashing
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int cond = nums.size()/2;
        for (auto it: nums) {
            m[it]++;
        }
        for (auto it: nums) {
            if(m[it] > cond) {
                return it;
            }
        }
        return -1;
    }
};

// Moore's Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int cnt = 0;
        for (auto it: nums) {
            if (cnt == 0) {
                el = it;
                cnt = 1;
            } else if (it == el) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return el;
    }
};
