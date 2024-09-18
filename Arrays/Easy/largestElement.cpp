// Following is the solution for: https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0

// Brute force: sorting the array

class Solution
{
public:
    // Function to find the largest element in the given vector
    int largest(vector<int> &arr, int n)
    {
        // Initialize max to the first element of the vector
        int max = arr[0];
        
        // Iterate through each element in the vector
        for(auto it : arr) {
            // If the current element is greater than max, update max
            if (it > max) {
                max = it;
            }
        }
        
        // Return the largest element found
        return max;
    }
};
