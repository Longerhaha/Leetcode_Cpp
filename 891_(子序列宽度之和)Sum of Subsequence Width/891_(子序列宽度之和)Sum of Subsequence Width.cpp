class Solution {
public:
    const int MOD = 1000000007;
    typedef long long ll;
    /*数学题
      排序后可以算出
      最大值是 a[i] 的子序列有2^i-1个
      最小值是 a[i] 的子序列有2^(N-1-i)-1个
      所以包含a[i] 的所有序列的和为 a[i] * (2^i - 2^(N-1-i))
      于是子序列宽度之和为 sum(a[i] * (2^i - 2^(N-1-i))), i = 0,1,2,..N-1
      
      为了避免数太大，可拆分为两个部分：
      1.sum(a[i] * 2^i), i = 0,1,2,..N-1
      2.sum(a[i] * 2^(N-1-i)), i = 0,1,2,..N-1
      上述两个式子在i很大的时候会溢出，所以需要采用如下思想：
      f(x) = a[0]x^(n-1) + a[1]x^(n-2) + ... + a[n-2]x + a[n-1]
           = ((...(((a[0]x + a[1])x + a[2])x + a[3]) + .... a[n-2]x) + a[n-1])                                      
      */
    int sumSubseqWidths(vector<int>& A) {
        int len = A.size();
        cout << len << endl;
        //1. 先排序
        sort(A.begin(), A.end());
        //2.1 算 add = sum( A[i] 作为子序列的最大元素的和), i = 0,1,2,...n-1
        ll add = 0;
        for( int i = len - 1; i >= 0; i-- ){
            add = (add * 2 + A[i]) % MOD;
        }
        //2.2 算 sub = sum( A[i] 作为子序列的最小元素的和), i = 0,1,2,...n-1
        ll sub = 0;
        for( int i = 0; i < len; i++ ){
            sub = (sub * 2 + A[i]) % MOD;
        }
        //2.3 算子序列宽度 sum = add - sub < 0 ? (add - sub + MOD) : (add - sub)
        ll sum = add - sub < 0 ? (add - sub + MOD) : (add - sub);
        return sum;
    }
};