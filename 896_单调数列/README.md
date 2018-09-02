# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 896_单调数列
## 问题描述、样例与输入输出

### 问题描述

如果数组是单调递增或单调递减的，那么它是单调的。

如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。

当给定的数组 A 是单调数组时返回 true，否则返回 false。

提示：

	* 1. 1 <= A.length <= 50000
	* 2. -100000 <= A[i] <= 100000

### 问题样例

	示例1：
	输入:
	[1,2,2,3]
	输出:
	true
	
	示例2：
	输入:
	[6,5,4,4]
	输出:
	true
	
	示例3：
	输入:
	[1,3,2]
	输出:
	false
	
	示例4：
	输入:
	[1,2,4,5]
	输出:
	true
	
	示例5：
	输入:
	[1,1,1]
	输出:
	true
	

函数输入与输出：
* 输入：
	* vector<int>& A：数组的引用
* 输出：
	* bool：是否是单调数列

## 思路			
### 定义法
	
	bool isMonotonic(vector<int>& A) {
        int len = A.size();
        if(len == 1)
            return true;
        /*
         * flag1是递增数组的标志，如果破坏递增数组的结果则更新为0
         * flag2是递减数组的标志，如果破坏递减数组的结果则更新为0
         */
        int flag1 = 1, flag2 = 1;
        for( int i = 1; i < A.size(); i++ ){
            if(A[i] - A[i - 1] < 0)
                flag1 = 0;
            if(A[i] - A[i - 1] > 0)
                flag2 = 0;
        }
        return  flag1 | flag2;
    }
	
## 拓展与思考：
### 拓展
如果让你判断是等差数列呢？
### 思考
本题较为简单。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
