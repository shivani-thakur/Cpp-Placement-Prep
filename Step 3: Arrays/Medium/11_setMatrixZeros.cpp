// Following is the solution for: https://leetcode.com/problems/set-matrix-zeroes/

// Brute Force
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRows = matrix.size(), nCols = matrix[0].size();
        int rows[nRows], cols[nCols];
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (rows[i] == 1 || cols[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Optimal (Space Optimized Approach)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nCol = 1;
        int nRows = matrix.size(), nCols = matrix[0].size();
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (matrix[i][j] == 0) {
                    if (j != 0) {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    } else {
                        nCol = 0;
                    }
                }
            }
        }
        for (int i = 1; i < nRows; i++) {
            for (int j = 1; j < nCols; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int i = 0; i < nCols; i++) {
                matrix[0][i] = 0;
            }
        }
        if (nCol == 0) {
            for (int i = 0; i < nRows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};