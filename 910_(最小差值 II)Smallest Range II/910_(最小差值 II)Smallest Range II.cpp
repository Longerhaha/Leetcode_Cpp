class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int len = A.size();
        sort(A.begin(), A.end());
        //ans 可能是A.back() - A.front()， 比如整体加 K 或者是减 K
        int n = A.size(), i, ans = A.back() - A.front();
        /*遍历寻找
          出发点是寻找以 A[i] + K, A[i + 1] - K为最大和最小元素的情况
          证明如下：
          不妨假设调整后的最大值与最小值的下标为i, j, 且 |i - j| > 1，即最大值是 A[i] + K, 最小值是 A[j] - K, 但是对于A[i + 1]，其加上 K 后比A[i] + K 大，减去 K 后比A[j] - K小，导出最大值是 A[i] + K, 最小值是 A[j] - K矛盾，所以|i - j| = 1
           进一步可以证明 i - j = 1
         */
        for( i = 0; i + 1 < n; i++ ) ans = min(ans, max(A[i] + K, A[n-1] - K) - min(A[0] + K, A[i + 1] - K));
        return ans;
    }
};