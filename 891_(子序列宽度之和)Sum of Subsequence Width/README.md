# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 891_(子序列宽度之和)Sum of Subsequence Width
## 问题描述、输入输出与样例

### 问题描述
给定一个整数数组 A ，考虑 A 的所有非空子序列。

对于任意序列 S ，设 S 的宽度是 S 的最大元素和最小元素的差。

返回 A 的所有子序列的宽度之和。

由于答案可能非常大，请返回答案模 10^9+7。


### 函数输入与输出

* 输入：
	* vector<int>& A：输入整数数组的引用
* 输出：
	* int：子序列的宽度之和
	
### 问题样例

	示例1:
	输入: 
	[2,1,3]
	  
	输出: 
	6
	
	解释：
	子序列为 [1]，[2]，[3]，[2,1]，[2,3]，[1,3]，[2,1,3] 。
	相应的宽度是 0，0，0，1，1，2，2 。
	这些宽度之和是 6 。
	
	提示：
	1. 1 <= A.length <= 20000
	2. 1 <= A[i] <= 20000
	
## 思路描述与代码	
### 思路描述（数学推导法）

排序后可以算出

最大值是 a[i] 的子序列有2^i-1个

最小值是 a[i] 的子序列有2^(N-1-i)-1个

所以包含a[i] 的所有序列的和为 a[i] * (2^i - 2^(N-1-i))

于是子序列宽度之和为 sum(a[i] * (2^i - 2^(N-1-i))), i = 0,1,2,..N-1

为了避免数太大，可拆分为两个部分：

1.sum(a[i] * 2^i), i = 0,1,2,..N-1

2.sum(a[i] * 2^(N-1-i)), i = 0,1,2,..N-1

上述两个式子在i很大的时候会溢出，所以需要采用如下思想
：
f(x) = a[0]x^(n-1) + a[1]x^(n-2) + ... + a[n-2]x + a[n-1]

	 = ((...(((a[0]x + a[1])x + a[2])x + a[3]) + .... a[n-2]x) + a[n-1])
	 
### 代码
	
	const int MOD = 1000000007;
    typedef long long ll;
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
 
 
## 拓展与思考：
### 拓展
如果让你求得是子串宽度之和呢？你可以从[907子数组的最小值之和](https://leetcode-cn.com/contest/weekly-contest-102/problems/sum-of-subarray-minimums/)获得灵感。
### 思考
本题属于数学题，如果你不去好好分析并求出来公式则解不出来，本题看似难，其实推导以后不难。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
