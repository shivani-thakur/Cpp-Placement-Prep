// Following is the solution for: https://leetcode.com/problems/missing-number

// O(n) using extra space
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Create a 'visited' vector initialized with 0s of size n+1 (where n is the size of nums)
        vector<int> visited(nums.size() + 1, 0);
        
        // Mark the positions corresponding to the elements present in 'nums'
        for(auto it: nums) {
            visited[it] = 1;  // Mark the index corresponding to the number as visited
        }
        
        // Find the index that was not visited, which is the missing number
        for (int i = 0; i < nums.size() + 1; i++) {
            if (visited[i] == 0) return i;  // Return the index that is not visited
        }
        
        return 0; // This should never be reached as one number is always missing
    }
};

// Sum of numbers approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        
        // Calculate the sum of all elements in the array 'nums'
        for (auto it: nums) {
            sum += it;  // Accumulate the sum of elements
        }
        
        // Calculate the expected sum of the first 'n' natural numbers (0 to n)
        int len = nums.size();
        int sum2 = (len * (len + 1)) / 2;
        
        // The difference between the expected sum and the actual sum is the missing number
        return sum2 - sum;
    }
};

// XOR approach can also be used