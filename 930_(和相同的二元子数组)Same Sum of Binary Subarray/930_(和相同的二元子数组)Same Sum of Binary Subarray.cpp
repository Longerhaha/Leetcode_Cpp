class Solution {
public:
    //动态规划
    int numSubarraysWithSum(vector<int>& A, int S) {
        int len_A = A.size();
        //dp[i] 代表 以A[0]为起始点的子数组且和为 i 的个数
        //则和为 S 的个数为 = sum(num[A[0]], num[A[1]], ..., num[A[len - 1]])，其中num[A[i]]是以A[i]为子数组的最后一个位置且和为 S 的个数
        //不妨记 sum_i = A[0] + A[1] + ... + A[i]
        //则 num[A[i]] = sum_i - S >= 0 ? dp[sum_i - S] : 0;
        vector<int> dp(len_A + 1, 0);
        dp[0] = 0;
        int sum = 0;
        int ans = 0;
        for( auto a : A ){
            dp[sum]++;
            sum += a;
            if(sum >= S) ans += dp[sum - S];
        }
        return ans;
    }
};