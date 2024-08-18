// Following is the solution for: https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Solution 1:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posEle, negEle;
        for (auto it: nums) {
            if (it < 0) {
                negEle.push_back(it);
            } else {
                posEle.push_back(it);
            }
        }
        vector<int> ans(nums.size());
        int j=0;
        for (int i= 0; i < nums.size()-1;i+=2) {
            ans[i] = posEle[j];
            ans[i+1] = negEle[j];
            j++;
        }
        return ans;
    }
};

// better
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posEle, negEle, ans(nums.size());
        int pi = 0, ni = 1;
        for (auto it: nums) {
            if (it < 0) {
                ans[ni] = it;
                ni += 2;
            } else {
                ans[pi] = it;
                pi += 2;
            }
        }
        return ans;
    }
};

// One more possibility: number of +ves and -ves is not same. Then use brute force approach.