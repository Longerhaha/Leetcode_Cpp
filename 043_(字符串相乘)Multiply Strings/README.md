# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 043_(字符串相乘)Multiply Strings
## 问题描述、输入输出与样例

### 问题描述

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

__说明__：

1. num1 和 num2 的长度小于110。
2. num1 和 num2 只包含数字 0-9。
3. num1 和 num2 均不以零开头，除非是数字 0 本身。
4. 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

### 函数输入与输出

* 输入：
	* string num1：表示非负整数 num1 的字符串
	* string num2：表示非负整数 num2 的字符串
* 输出：
	* string：乘积的结果的字符串形式
	
### 问题样例

#### 示例1

输入: num1 = "2", num2 = "3"

输出: "6"

#### 示例2

输入: num1 = "123", num2 = "456"

输出: "56088"
	
	
## 思路描述与代码	
### 思路描述（反序相乘法）
num1 、 num2 字符串反序，方便从低往高位做乘法，反序相乘的结果 ans 是其未反序相乘结果的反序，所以最后输出时只要把 ans 反序即可。
```cpp
for( int i = 0; i < len_num2; i++ ){
	carry = 0;
	//当前结果的位宽
	len_ans = ans.size();
	for( int j = 0; j < len_num1; j++ ){
		//如果在结果字符串的位宽内则需要与之前的结果相加
		if(i + j < len_ans){
			//算一位乘一位的乘法
			single_product = (num1[j] - '0') * (num2[i] - '0') + carry + ans[i + j] - '0';
			carry = single_product / 10;
			ans[i + j] = single_product % 10 + '0';
		}
		//超出结果字符串位宽则在后面添
		else{
			single_product = (num1[j] - '0') * (num2[i] - '0') + carry;
			carry = single_product / 10;
			ans.push_back(single_product % 10 + '0');
		}
	}
	//如果有进位
	if(carry) ans.push_back(carry + '0');
}
//结果反序
reverse(ans.begin(), ans.end());
```



### 代码
```cpp
string multiply(string num1, string num2) {
	int len_num1 = num1.size();
	int len_num2 = num2.size();
	//输出为0的处理
	if(len_num1 == 0 ||  (len_num1 == 1 && num1 == "0") || len_num2 == 0 || (len_num2 == 1 && num2 == "0")) return "0";
	//反序方便相乘
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	string ans(len_num1, '0');
	for( int i = 0; i < len_num2; i++ ){
		int carry = 0;
		int len_ans = ans.size();
		for( int j = 0; j < len_num1; j++ ){
			//如果在结果字符串的位宽内则需要与之前的结果相加
			if(i + j < len_ans){
				//算一位乘一位的乘法
				int single_product = (num1[j] - '0') * (num2[i] - '0') + carry + ans[i + j] - '0';
				carry = single_product / 10;
				ans[i + j] = single_product % 10 + '0';
			}
			//超出结果字符串位宽则在后面添
			else{
				int single_product = (num1[j] - '0') * (num2[i] - '0') + carry;
				carry = single_product / 10;
				ans.push_back(single_product % 10 + '0');
			}
		}
		//如果有进位
		if(carry) ans.push_back(carry + '0');
	}
	//结果反序
	reverse(ans.begin(), ans.end());
	return ans;
}
```
## 思考与拓展
### 思考
本题反序了之后较好操作，大数（比如 BigInteger）类的问题都可以按这种类似的计算方式解决。
### 拓展
这类题目都是大数问题，可以采用字符串或者数组来表示大数。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
