class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int len = A.size();
        sort(A.begin(), A.end());
        if(A[len - 1] - A[0] <= 2 * K) return 0;
        else return A[len - 1] - A[0] - 2 * K;
    }
};