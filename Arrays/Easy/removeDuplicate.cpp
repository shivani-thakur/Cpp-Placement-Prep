// Following is the solution for: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize two pointers: 
        // 'i' to track the position of the last unique element in the array.
        // 'j' to traverse through the array and find new unique elements.
        int i = 0; 
        int j = 1; 

        // Get the size of the array
        int l = nums.size(); 

        // Loop through the array using 'j' as the traversal pointer
        while(j < l) {
            // Store the current element at index 'i' in variable 'f'
            int f = nums[i]; 

            // Move 'j' forward as long as it points to a duplicate of 'f'
            while (j < l && (nums[j] == f)) j++; 

            // If 'j' is still within bounds, it means we've found a new unique element
            if (j < l) {
                // Move the unique element found at 'j' to the position after 'i'
                nums[i + 1] = nums[j]; 
                // Increment 'i' to point to the new last unique element
                i++; 
            }
        }
        
        // Return the number of unique elements, which is 'i + 1'
        return i + 1; 
    }
};
