# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 917_(仅仅反转字母)Just Reverse the Letters
## 问题描述、输入输出与样例

### 问题描述

给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

### 函数输入与输出

* 输入：
	* string S：给定的字符串 S
* 输出：
	* string：仅仅反转字母后的字符串 S
	
### 问题样例

#### 示例1

输入："ab-cd"

输出："dc-ba"

#### 示例2

输入："a-bC-dEf-ghIj"

输出："j-Ih-gfE-dCba"

#### 示例3

输入："Test1ng-Leet=code-Q!"

输出："Qedo1ct-eeLg=ntse-T!"
	
## 思路描述与代码	
### 思路描述（双下标反转法）
其与字母反转仅仅多加了个条件而已。

多加每次 start、end 跳过非字母字符操作，其余是一样的思想。
### 代码
```cpp
string reverseOnlyLetters(string S) {
	int len = S.size();
	int start = 0, end = len - 1;
	while( start < end ){
		//先跳过非字母字符
		while( start < end && (S[start] < 'A' || (S[start] > 'Z' && S[start] < 'a') || S[start] > 'z') ) start++;
		while( start < end && (S[end] < 'A' || (S[end] > 'Z' && S[end] < 'a') || S[end] > 'z') ) end--;
		swap(S[start], S[end]);
		start++, end--;
	}
	return S;
}
```
## 思考与拓展
### 思考
本题也较为简单。
### 拓展
暂无想法。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
