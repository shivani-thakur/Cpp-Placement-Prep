// Following is the solution for: https://leetcode.com/problems/move-zeroes/


// Brute Force Solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        vector<int> temp;  // Temporary vector to store non-zero elements
        int cnt = 0;  // Counter for the number of zeroes
        
        // Traverse the array and store non-zero elements in 'temp'
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                temp.push_back(nums[i]);
            } else {
                cnt++;  // Count the zeroes
            }
        }
        
        // Append 'cnt' number of zeroes to the end of 'temp'
        for (int i = 0; i < cnt; i++) {
            temp.push_back(0);
        }
        
        // Copy the elements from 'temp' back to the original array
        for (int i = 0; i < len; i++) {
            nums[i] = temp[i];
        }
    }
};


// Solution 2 (Using Extra Space)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        vector<int> temp(len);  // Temporary vector of the same size as 'nums'
        int cnt = 0;  // Counter for zeroes
        int j = len - 1;  // Pointer for placing zeroes at the end
        int x = 0;  // Pointer for placing non-zero elements at the start
        
        // Traverse the array
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                temp[x] = nums[i];  // Place non-zero element in the front of 'temp'
                x++;
            } else {
                temp[j] = 0;  // Place zero at the end of 'temp'
                j--;
            }
        }
        
        // Copy the elements from 'temp' back to the original array
        for (int i = 0; i < len; i++) {
            nums[i] = temp[i];
        }
    }
};


// Optimal Approach (In-Place)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int j = -1;  // Pointer for the first zero encountered
        int i = -1;  // Pointer for the current element
        
        // Find the first zero in the array
        for (i = 0; i < len; i++) {
            if (nums[i] == 0) {
                break;
            }
        }
        j = i;  // 'j' points to the first zero
        i = i + 1;  // 'i' starts checking from the next element
        
        // Traverse the array to move non-zero elements to the front
        while (i < len) {
            if (nums[i] != 0) {
                // Swap the non-zero element with the zero at index 'j'
                swap(nums[j], nums[i]);
                j++;  // Move 'j' to the next zero
            }
            i++;  // Move to the next element
        }
    }
};
