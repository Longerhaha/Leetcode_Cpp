# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 907_(子数组的最小值之和)Sum of Minimum Data of All Subarray
## 问题描述、输入输出与样例

### 问题描述

给定一个整数数组 A，找到 min(B) 的总和，其中 B 的范围为 A 的每个（连续）子数组。

由于答案可能很大，因此返回答案模 10^9 + 7。

### 函数输入与输出

* 输入：
	* vector<int>& A：输入数组的引用
* 输出：
	* int：所有子数组的最小值之和
	
### 问题样例

	示例1:
	输入: 
	[3,1,2,4]
	  
	输出: 
	17
	
	解释：
	子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。 
	最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
	
	提示：
	1. 1 <= A <= 30000
	2. 1 <= A[i] <= 30000
	
## 思路描述与代码	
### 思路描述（动态规划）
首先分析题目，如果我们把所有的子数组列举出来并算最小值，计算复杂度至少是 log(n) * n，所以别想了肯定不是用这种方法。换个思路想一想，
以数据A[i]为最小的子数组有多少个？如果突破了这个问题，这道题目就简单了。
	
数据 A[i] 为最小的子数组有多少个？先计算左边连续比他大的数有x个，再计算右边连续比他大的数有y个，那么就有(x+1)*(y+1)中可能的子序列。
于是问题进一步转换为求 A[i] 左连续大于或等于他的个数(为了代码写的方便，我这里算x + 1而不是x)，右连续大于他的个数（这里没有等于是为了
避免相等数据的多次计算）。

如果你用动态规划做过[901股票价格跨度](https://leetcode-cn.com/contest/weekly-contest-101/problems/online-stock-span/)，那接下来就迎刃而解了。
求个数的问题用动态规划做最简答了，否则会死于最恶劣的情况（不断从某个节点统计到头，在统计到尾巴，O（n^2）的时间复杂度）。	
	
	
### 代码
	const int MOD = 1000000007;
    int sumSubarrayMins(vector<int>& A) {
        int len = A.size();
        /*
         这种方法不行，最坏的情况有O（n^2）
        int left = 0, right = 0;
        int sum = 0;
        for( int i = 0; i < len; i++ ){
            left = i - 1;
            while( left >= 0 && A[left] >= A[i] ) left--;
            right = i + 1;
            while( right < len && A[right] > A[i]) right++;
            
            int left_cnt = i - left;
            int right_cnt = right - i;
            //cout << left_cnt << " " << right_cnt << endl;
            sum += (right_cnt * left_cnt * A[i]) % MOD;
            sum = sum % MOD;
        }*/
        vector<int> left(len, -1);
        vector<int> right(len, -1);
        //从右往左找与他相等或者比他大的数有几个，包括他自己
        for( int i = 0; i < len; i++ ){
            int pre_pos = i - 1;
            while( pre_pos >= 0 && A[i] <= A[pre_pos]) pre_pos -= left[pre_pos];
            left[i] = i - pre_pos;
        }
        //从左往右找找比他大的数有几个，包括他自己
        //这里没有等号的原因是：可能有相等的数据，则右往左找的时候统计一次，左往右找的时候统计一次，统计了多次
        for( int i = len - 1; i >= 0; i-- ){
            int next_pos = i + 1;
            while( next_pos < len && A[i] < A[next_pos]) next_pos += right[next_pos];
            right[i] = next_pos - i;
        }
         
        //以A[i]为最小值的子序列的可能性有 left[i] * right[i] 种
        //对所有情况进行累加即可
        int sum = 0;
        for( int i = 0; i < len; i++ ){
            //cout << left[i] << " " << right[i] << endl;
            sum = (sum + left[i] * right[i] * A[i]) % MOD;
        }
        return sum;
    }
 
 
## 拓展与思考：
### 拓展
如果让你求子数组的最大值之和？改个符号就好啦。
### 思考
本题相比于[891子序列宽度之和](https://leetcode-cn.com/contest/weekly-contest-98/problems/sum-of-subsequence-widths/)还是简单了点，对于这类问题都要转换下思维。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
