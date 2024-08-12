// Following is the solution for: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

class Solution{
    public:
    //arr1, arr2: the arrays
    //n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> v; // Result vector to store the union of the arrays
        int i = 0, j = 0; // Pointers for arr1 and arr2
        int lastInserted = -1; // Variable to track the last inserted element in 'v'

        // Traverse both arrays until one of them is exhausted
        while (i < n && j < m) {
            // If the current element in arr1 is smaller
            if (arr1[i] < arr2[j]) {
                // Add the element to 'v' if it is not the same as the last inserted element
                if (lastInserted != arr1[i]) {
                    v.push_back(arr1[i]);
                    lastInserted = arr1[i];
                }
                i++; // Move to the next element in arr1
            }
            // If the current element in arr2 is smaller
            else if (arr1[i] > arr2[j]) {
                // Add the element to 'v' if it is not the same as the last inserted element
                if (lastInserted != arr2[j]) {
                    v.push_back(arr2[j]);
                    lastInserted = arr2[j];
                }
                j++; // Move to the next element in arr2
            }
            // If elements are equal in both arrays
            else {
                // Add the element to 'v' if it is not the same as the last inserted element
                if (lastInserted != arr1[i]) {
                    v.push_back(arr1[i]);
                    lastInserted = arr1[i];
                }
                i++; // Move to the next element in both arrays
                j++;
            }
        }

        // Store remaining elements of arr1[]
        while (i < n) {
            // Add the element to 'v' if it is not the same as the last inserted element
            if (v.empty() || v.back() != arr1[i]) {
                v.push_back(arr1[i]);
            }
            i++; // Move to the next element in arr1
        }

        // Store remaining elements of arr2[]
        while (j < m) {
            // Add the element to 'v' if it is not the same as the last inserted element
            if (v.empty() || v.back() != arr2[j]) {
                v.push_back(arr2[j]);
            }
            j++; // Move to the next element in arr2
        }

        return v; // Return the union of the two arrays
    }
};
