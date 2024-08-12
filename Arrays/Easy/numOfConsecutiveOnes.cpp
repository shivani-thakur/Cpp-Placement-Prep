// Following is the solution for: https://leetcode.com/problems/max-consecutive-ones

// Solution 1:
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prev = 0, curr = 0;  // 'prev' stores the max count found so far, 'curr' counts the current sequence of 1s
        
        // Iterate through each element in the array
        for (auto it: nums) {
            if (it == 1) {
                // If the current element is 1, increment the current count
                curr++;
            } else {
                // If the current element is not 1 (i.e., it's 0)
                // Check if the current sequence is the longest so far
                if (curr > prev) {
                    prev = curr;  // Update the maximum found so far
                }
                curr = 0;  // Reset the current count for the next sequence of 1s
            }
        }
        
        // After the loop, compare the last counted sequence with the max found so far
        return ((curr > prev) ? curr : prev);  // Return the maximum of the last sequence or previous max
    }
};
