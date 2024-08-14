// Following is the solution for: https://leetcode.com/problems/sort-colors

// Brute force is to use any sorting algorithm.

// Better solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3,0);
        for (auto it: nums) {
            v[it]++;
        }
        for(int i=0; i< v[0]; i++){
            nums[i] = 0;
        }
        int offset = v[0];
        for (int i = 0; i < v[1]; i++) {
            nums[offset+i] = 1;
        }
        offset = v[0] + v[1];
        for (int i = 0; i < v[2]; i++) {
            nums[offset+i] = 2;
        }
    }
};

// Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};