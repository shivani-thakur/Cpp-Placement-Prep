// Following is the solution for: https://leetcode.com/problems/longest-consecutive-sequence/

// Brute force
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestLen = 0, len = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            len = 0;
            while(find(temp, nums)) {
                len++;
                temp++;
            }
            longestLen = max(longestLen, len);
        }
        return longestLen;
    }
    bool find(int val, vector<int>& nums) {
        for (auto it: nums) {
            if (it == val) return true;
        }
        return false;
    }
};

// Other Solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lastInSeq = INT_MIN;
        int len = 0, maxLen = 0;
        for (auto it: nums) {
            if (it == (lastInSeq+1)) {
                len++;
                lastInSeq = it;
                maxLen = max(maxLen, len);
            }
            else if (it != (lastInSeq+1) && it != lastInSeq) {
                lastInSeq = it;
                len = 1;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};

// 3rd Solution - Using Set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it: nums) {
            s.insert(it);
        }
        int len = 0, maxLen = 0;
        for(auto it: s) {
            if (s.find(it-1) == s.end()) {
                int temp = it;
                len = 0;
                while (s.find(temp) != s.end()) {
                    temp++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};