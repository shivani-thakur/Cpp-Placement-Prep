// Following is the solution for: https://leetcode.com/problems/intersection-of-two-arrays/

// Brute Force
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        set<int> s;
        for(int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    s.insert(nums1[i]);
                    break;
                }
            }
        }
        for (auto it: s) {
            v.push_back(it);
        }
        return v;
    }
};