//Following is the solution for: https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // Get the length of the array
        int len = arr.size();
        
        // Store the last element of the array
        int lastEle = arr[len - 1];
        
        // Initialize 'prev' with the first element of the array
        int prev = arr[0];
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < len; i++) {
            // Temporarily store the current element
            int temp = arr[i];
            
            // Replace the current element with the previous element
            arr[i] = prev;
            
            // Update 'prev' to be the current element for the next iteration
            prev = temp;
        }
        
        // After shifting all elements to the right, place the last element at the first position
        arr[0] = lastEle;
    }
};
