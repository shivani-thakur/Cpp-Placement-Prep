// Following is the solution for: https://www.geeksforgeeks.org/problems/second-largest3735/1

// brute force:
/*
1. apply sorting algorithm to sort the array in ascending array.
2. start traversing from the end of the array.
3. continue traversal till 2nd largest element is not reached. ex. 1, 2, 4, 5, 7, 7
*/

// Better Approach:
class Solution {
public:
    // Function returns the second largest element in the vector
    int print2largest(vector<int> &arr) {
        // Initialize max to the first element of the vector
        int max = arr[0];
        
        // First pass to find the largest element
        for (auto it : arr) {
            if (it > max) {
                max = it; // Update max if a larger element is found
            }
        }
        
        // Initialize secMax (second largest) to -1 (assuming all elements are non-negative)
        int secMax = -1;
        
        // Second pass to find the second largest element
        for (auto it : arr) {
            if (it > secMax && it != max) {
                secMax = it; // Update secMax if a larger element (not equal to max) is found
            }
        }
        
        // Return the second largest element
        return secMax;
    }
};

// Optimal Approach:
int print2largest(vector<int> &arr) {
    // Initialize max1 (largest) to the first element, max2 (second largest) to -1
    int max1 = arr[0], max2 = -1;
    
    // Single pass to find both the largest and second largest elements
    for (auto it : arr) {
        if (it > max1) {
            // If current element is greater than max1, update max2 to max1 and max1 to current element
            max2 = max1;
            max1 = it;
        } else if (it > max2 && it != max1) {
            // If current element is greater than max2 but less than max1, update max2
            max2 = it;
        }
    }
    
    // Return the second largest element
    return max2;
}
