// Following is the solution for: https://leetcode.com/problems/pascals-triangle/description/

/*
This question has 3 variations.
1. Given row and column number, print the element in given row and column.
2. Given row number, print entire row.
3. Given number of rows, print entire triangle.

For 1,
Formula is (r-1)C(c-1) {i.e. combination of r-1 and c-1}. r is row number, c is column number.
ans = 1
for (int i = 0; i < c; i++) {
ans = ans * (r-i);
ans = ans / (i+1);
}

For 2,
ans = 1;
print(ans);
for (int i = 1; i < r; i++) {
ans = ans * (r-i);
ans = ans/i;
print(ans);
}
*/

// 3rd type: print entire triangle
class Solution {
public:
    vector<int> getRow (vector<int>& prevRow) {
        vector<int> ans;
        ans.push_back(1);
        int n = prevRow.size();
        for(int i = 0; i < n - 1; i++) {
            ans.push_back(prevRow[i]+prevRow[i+1]);
        }
        ans.push_back(1);
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;
        prev.push_back(1);
        ans.push_back(prev);
        for (int i = 1; i < numRows; i++) {
            vector<int> temp = getRow(prev);
            ans.push_back(temp);
            prev = temp;
        }
        return ans;
    }
};