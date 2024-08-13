// Following is the solution for: https://leetcode.com/problems/single-number


// Using XOR
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto it: nums) {
            ans ^= it;
        }
        return ans;
    }
};

// Hashing can also be used. But since range of numbers is high, hash array will be big.

// Map also can be used. Store key and corresponding count in the map. traverse at the end and return key with count 1.

// Nested loop approach is also there. Outer loop for picking the array element and inner loop for counting its occurance.

// SUM OF ELEMENTS
/* All the unique elements , in the array have a frequency of 2 , except one element.

Store all the unique elements in set.
Add the elements of the set and multiply by 2 (SUM_1).
Add all the elements of the array(ARRAY_SUM).
Return (SUM_1 - ARRAY_SUM) .*/