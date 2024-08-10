// Following is the solution for: https://leetcode.com/problems/rotate-array/

// Brute Force Solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        
        // Perform the rotation 'k' times
        for (int i = 0; i < k; i++) {
            // Store the last element to move it to the front
            int last = nums[len - 1];
            
            // Shift all elements to the right by one position
            for (int j = len - 1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }
            
            // Place the last element at the first position
            nums[0] = last;
        }
    }
};

// Using Extra Space Solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        
        // Create a temporary array to store the rotated version
        vector<int> temp(len);
        
        // Place each element in its new rotated position
        for (int i = 0; i < len; i++) {
            temp[(i + k) % len] = nums[i];
        }
        
        // Copy the rotated array back to the original array
        for (int i = 0; i < len; i++) {
            nums[i] = temp[i];
        }
    }
};

// Better Solution (Using Reversals)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // In case k is greater than the length of the array, use modulus
        k %= nums.size();
        
        // Reverse the entire array
        reverse(nums, 0, nums.size() - 1);
        
        // Reverse the first 'k' elements
        reverse(nums, 0, k - 1);
        
        // Reverse the remaining elements
        reverse(nums, k, nums.size() - 1);
    }

private:
    // Helper function to reverse a portion of the array
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            // Swap the elements at 'left' and 'right'
            swap(nums[left], nums[right]);
            
            // Move towards the center
            left++;
            right--;
        }
    }    
};
