// Following is the solution for: https://leetcode.com/problems/merge-intervals/description/

// Brute (TC: O(nlogn) + O(2n))


// Optimal (TC: O(nlogn) + O(n))
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        int n = intervals.size();
        for(int i = 1; i < n; i++) {
            if (temp[1] >= intervals[i][0]) {
                if (temp[1] < intervals[i][1]) {
                    temp[1] = intervals[i][1];
                }
            } else {
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
