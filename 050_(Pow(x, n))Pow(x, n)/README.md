# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 050_(Pow(x, n))Pow(x, n)
## 问题描述、输入输出与样例

### 问题描述

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

__说明__:

* -100.0 < x < 100.0
* n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。

### 函数输入与输出

* 输入：
	* double x：幂底数
	* int n：幂指数
* 输出：
	* double： x 的 n 次幂的结果
	
### 问题样例

#### 示例1

输入: 2.00000, 10

输出: 1024.00000

#### 示例2

输入: 2.10000, 3

输出: 9.26100

#### 示例3

输入: 2.00000, -2

输出: 0.25000

解释: 2-2 = 1/2^2 = 1/4 = 0.25
	
	
## 思路描述与代码	
### 思路描述（二分法）
	
	x^n = x^(n / 2) * x^(n / 2), 					n 为偶数
		= x * x^((n - 1) / 2) * x^((n - 1)  / 2),   n 为奇数
		
### 代码
```cpp
double myPow(double x, int n) {
	if (n < 0) return 1.0 / unsigned_power(x, -n);
	else return unsigned_power(x, n);
}

double unsigned_power(double x, int n) {
	if (n == 0) return 1;
	//if (n & 0x01) return x * unsigned_power(x, n / 2) * unsigned_power(x, n / 2);
	//else return unsigned_power(x, n / 2) * unsigned_power(x, n / 2);
	double v = unsigned_power(x, n / 2);
	if (n & 0x01) return x * v * v;
	else return v * v;
}
```
## 思考与拓展
### 思考
利用二分的思想很容易解决该问题，值得注意的是注意负数的处理。
### 拓展
暂无想法。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
