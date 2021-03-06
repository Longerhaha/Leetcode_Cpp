# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 910_(最小差值 II)Smallest Range II
## 问题描述、输入输出与样例

### 问题描述

给定一个整数数组 A，对于每个整数 A[i]，我们可以选择 x = -K 或是 x = K，并将 x 加到 A[i] 中。

在此过程之后，我们得到一些数组 B。

返回 B 的最大值和 B 的最小值之间可能存在的最小差值。

### 函数输入与输出

* 输入：
	* vector<int>& A：给定的整数数组 A
	* int K：可以加减的值 K
* 输出：
	* int：B 的最大值和 B 的最小值之间可能存在的最小差值
	
### 问题样例

#### 示例1

	输入: A = [1], K = 0
	输出: 0
	解释：B = [1]
	
#### 示例2

	输入: A = [0,10], K = 2
	输出: 6
	解释：B = [2,8]

#### 示例3

	输入: A = [1,3,6], K = 3
	输出: 3
	解释：B = [4,6,3]
	
提示：

1. 1 <= A.length <= 10000
2. 0 <= A[i] <= 10000
3. 0 <= K <= 10000
	
	
## 思路描述与代码	
### 思路描述（排序、一遍扫描法）

引理：对于一个有序数组，其值要么选择加 K 或者减 K ，数组经过这样的处理后的最大值与最小值出现的下标为i、 j，则 i - j = 1。

证明如下：

不妨假设有序数组是升序数组，调整后的最大值与最小值的下标为i, j, 且 i - j > 1，即最大值是 A[i] + K, 最小值是 A[j] - K, 但是对于A[i + 1]，
其加上 K 后比A[i] + K 大，减去 K 后比A[j] - K小，与最大值是 A[i] + K, 最小值是 A[j] - K矛盾，所以 i - j = 1。

同理如果有序数组是降序数组，则j - i = 1。

有了引理，就可以很简答的解决问题了，直接一遍扫描即可。


### 代码

	int smallestRangeII(vector<int>& A, int K) {
        int len = A.size();
        sort(A.begin(), A.end());
        //ans 可能是A.back() - A.front()， 比如整体加 K 或者是减 K
        int n = A.size(), i, ans = A.back() - A.front();

        for( i = 0; i + 1 < n; i++ ) ans = min(ans, max(A[i] + K, A[n-1] - K) - min(A[0] + K, A[i + 1] - K));
        return ans;
    }
 
## 拓展与思考：
### 拓展
如果给你的是链表数据呢？
### 思考
如果没有引理，你很容易陷入思路的困惑。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
