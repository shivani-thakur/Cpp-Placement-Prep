// Following is the solution for: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

// Brute force
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int len = 0;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j=i; j < N; j++) {
                sum += A[j];
                if (sum == K) {
                    len = max(len, j-i+1);
                }
            }
        }
        return len;
    } 

};

// Using Hashing
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<long long, int> m;
        int len = 0;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];
            if (sum == K) {
                len = max(len, i+1);
            }
            long long remSum = sum - K;
            if (m.find(remSum) != m.end()) {
                len = max(len, i - m[remSum]);
            }
            
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }
        }
        return len;
    } 

};

// 2 Pointer approach(only for array having positive numbers, striver approach bit different, check again)
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int K) 
    { 
        int i = 0, j = 0;
        int len = 0;
        long long sum = 0;
        while (j < n) {
            sum += A[j];
            if (sum == K) {
                len = max(len, j);
            }
            while (sum > K && i<= j) {
                sum -= A[i];
                i++;
            }
            j++;
        }
        return len+1;
    }
};
