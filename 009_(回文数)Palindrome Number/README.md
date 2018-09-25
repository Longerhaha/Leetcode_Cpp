# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 009_(回文数)Palindrome Number
## 问题描述、输入输出与样例

### 问题描述

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

### 函数输入与输出

* 输入：
	* int x：输入的整数 x
* 输出：
	* bool：判断 x 是不是回文数
	
### 问题样例

#### 示例1

	输入: 121
	输出: true
	
#### 示例2

	输入: -121
	输出: false
	解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

#### 示例3

	输入: 10
	输出: false
	解释: 从右向左读, 为 01 。因此它不是一个回文数。
	
#### 进阶
你能不将整数转为字符串来解决这个问题吗？
	
	
## 思路描述与代码	
### 思路描述（反转法）

求 x反序的大小，然后判断反序大小是否与 x 相等。

### 代码

	bool isPalindrome(int x) {
        if( x < 0) return false;
        
        //求逆序所代表的数的大小
        int x_tmp = x;
        int opposite_x = 0;
        while( x_tmp ){
            opposite_x = opposite_x * 10 + x_tmp % 10;
            x_tmp /= 10;
        }
        return opposite_x == x;
    }
 
 
## 拓展与思考：
### 拓展
暂无想法。
### 思考
本题较为简单。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
