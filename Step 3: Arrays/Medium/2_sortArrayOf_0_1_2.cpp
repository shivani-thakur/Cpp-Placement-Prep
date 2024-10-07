// Following is the solution for: https://leetcode.com/problems/sort-colors/

// Brute Force (using merge sort)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) return;

        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    void merge(vector<int>& nums, int low, int mid, int high) {
        int i1 = low, i2 = mid + 1;
        vector<int> v;
        while(i1 <= mid && i2 <= high) {
            if (nums[i1] <= nums[i2]) {
                v.push_back(nums[i1]);
                i1++;
            } else {
                v.push_back(nums[i2]);
                i2++;
            }
        }
        while(i1 <= mid) {
            v.push_back(nums[i1]);
            i1++;
        }
        while(i2 <= high) {
            v.push_back(nums[i2]);
            i2++;
        }
        int i = low;
        for(auto it: v) {
            nums[i] = it;
            i++;
        }
    }
};

// Better (counting 0s, 1s, 2s)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, cnt0 = 0;
        for(auto it: nums) {
            if (it == 0) cnt0++;
            else if (it == 1) cnt1++;
            else cnt2++;
        }
        for (int i = 0; i < cnt0; i++) {
            nums[i] = 0;
        }
        for (int i = cnt0; i < cnt0+cnt1; i++) {
            nums[i] = 1;
        }
        for (int i = cnt0+cnt1; i < nums.size(); i++) {
            nums[i] = 2;
        }
    }
};

// Optimal (Dutch National Flag Algorithm)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
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