// Following is the solution for: https://leetcode.com/problems/majority-element/

// Brute force
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == nums[i]) cnt++;
            }
            if (cnt > (nums.size()/2)) return nums[i];
        }
        return -1;
    }
};

// Better (Using Hashing)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (auto it: nums) {
            m[it]++;
        }
        int target = nums.size()/2;
        for (auto it: m) {
            if(it.second > target) {
                return it.first;
            }
        }
        return -1;
    }
};

// Optimal (Moore's Voting Algorithm)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el, cnt = 0;
        for (auto it: nums) {
            if (cnt == 0) {
                el = it;
                cnt++;
            } else if (it == el) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return el;
        // If majority element exists, it will be stored in el.
        // If question says majority element may or may not exists, just count the el in the array.
    }
};