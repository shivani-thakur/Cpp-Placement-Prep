// Following is the solution for: https://leetcode.com/problems/single-number/


// Brute force: pick 1 to N numbers and count the frequency in the array

// Using Map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<long long, int> m;
        for(auto it: nums) {
            m[it]++;
        }
        for(auto it: m) {
            if(it.second == 1) {
                return it.first;
            }
        }
        return 0;
    }
};

// Optimal using XOR
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto it: nums) {
            x ^= it;
        }
        return x;
    }
};