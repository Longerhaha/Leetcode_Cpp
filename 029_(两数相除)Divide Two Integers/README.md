# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 029_(两数相除)Divide Two Integers
## 问题描述、输入输出与样例

### 问题描述

给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

__说明__:

* 被除数和除数均为 32 位有符号整数。
* 除数不为 0。
* 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

### 函数输入与输出

* 输入：
	* int dividend：被除数
	* int divisor：除数
* 输出：
	* int：商
	
### 问题样例

#### 示例1

输入: dividend = 10, divisor = 3

输出: 3

#### 示例2

输入: dividend = 7, divisor = -3

输出: -2
	
	
## 思路描述与代码	
### 思路描述（位运算）
除法的位运算需要考虑溢出的问题，比如四字节的 int 的被除数 -2147483648 和除数 -1，其商是 2147483648，已经超出了 int 所能表示的最大范围。

除法的位运算法主要步骤如下：
1. 被除数、除数求绝对值；
2. 求被除数的 msb；
3. 利用减法做除法；
4. 符号校正。

### 代码
```cpp
const int MAX_INT = 2147483647;
const int MSB_MASK = 0x80000000; 
int divide(int dividend, int divisor) {
	//求模
	long int abs_dividend = dividend < 0 ? -((long int)dividend) : dividend;
	long int abs_divisor = divisor < 0 ? -((long int)divisor) : divisor;
	
	if(abs_dividend < abs_divisor) return 0;
	
	//求被除数的最高位
	int msb = 31;
	while( !(abs_dividend & (1 << msb)) ) msb--;
	
	//开始做正整数的除法
	long int R = abs_dividend;//余数
	long int Q = 0;//商
	for( int i = msb; i >= 0; i-- ){
		if((abs_divisor << i) > R) continue;
		Q |= (1 << i);
		R -= (abs_divisor << i);
	}
	//校正
	Q = Q > 0 ? Q : -Q;
	Q = (dividend & MSB_MASK) == (divisor & MSB_MASK) ? Q : -Q;
	Q = Q > MAX_INT ? MAX_INT : Q;
	
	return Q;
}
```
## 思考与拓展
### 思考
主要要考虑溢出问题，其他都较为常规。
### 拓展
在数字电路里面，除法的实现有非恢复余数除法、恢复余数除法、级数展开除法和 Newton-Raphson算法的除法器，感兴趣的可以了解一下。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
