//Following is the solution for: https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int l = arr[arr.size()-1];
        for(int j = arr.size()-2; j >= 0; j--) {
            arr[j+1] = arr[j];
        }
        arr[0] = l;
    }
};
