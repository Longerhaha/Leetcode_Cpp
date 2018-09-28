# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 006_(Z字形变换)ZigZag Conversion
## 问题描述、输入输出与样例

### 问题描述

P   A   H   N

A P L S I I G

Y   I   R

之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"

实现一个将字符串进行指定行数变换的函数:

string convert(string s, int numRows);

### 函数输入与输出

* 输入：
	* string s：输入的字符串s 
	* int numRows：指定行数变换
* 输出：
	* string：变换后的字符串
	
### 问题样例

#### 示例1
输入: s = "PAYPALISHIRING", numRows = 3

输出: "PAHNAPLSIIGYIR"

#### 示例2
输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:

P     I    N
A   L S  I G
Y A   H R
P     I
	
	
## 思路描述与代码	
### 思路描述（找规律法）

把输入的字符串分行后，可以找到如下规律：
1. 第 1 和 numRows行每个数的间隔是 2 * numRows - 2
2. 其余行以头两个数（第一个数是i， 第二数是 2 * numRows - i - 2）间隔为 2 * numRows - 2分布。

然后遍历就可以了。

### 代码

string convert(string s, int numRows) {
	if(numRows == 1) return s;
	string s_convert;
	for( int i = 0; i < numRows; i++ ){
		if(i == 0 || i == numRows - 1){
			int j = i;
			while( j < s.size() ){
				s_convert.push_back(s[j]);
				j += (2 * numRows - 2);
			}
		}
		else{
			int idx_1 = i, idx_2 = 2 * numRows - i - 2;
			while( idx_1 < s.size() || idx_2 < s.size()){
				if(idx_1 < s.size()) s_convert.push_back(s[idx_1]);
				if(idx_2 < s.size()) s_convert.push_back(s[idx_2]);
				idx_1 += (2 * numRows - 2);
				idx_2 += (2 * numRows - 2);
			}
		}
	}
	return s_convert;
} 
 
## 拓展与思考：
### 拓展
可以原地修改吗？
### 思考
本题纯属找规律。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
