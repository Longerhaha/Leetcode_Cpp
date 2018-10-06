# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 020_(有效的括号)Valid Parantheses
## 问题描述、输入输出与样例

### 问题描述

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
* 左括号必须用相同类型的右括号闭合。
* 左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

### 函数输入与输出

* 输入：
	* string s：输入的字符串 s
* 输出：
	* bool：是否是有效的括号
	
### 问题样例

#### 示例1

输入: "()"

输出: true

#### 示例2

输入: "()[]{}"

输出: true

#### 示例3

输入: "(]"

输出: false

#### 示例4

输入: "([)]"

输出: false

#### 示例5

输入: "{[]}"

输出: true
	
## 思路描述与代码	
### 思路描述（堆栈法）
遍历输入的字符串 s 的所有字符 c：
	* 如果是左括号则入栈
	* 如果是右括号：
		* 栈非空或者顶非对应的左括号则肯定不是有效的括号，返回false
		* 否则将栈顶元素出栈
遍历结束后，查看堆栈是否为空。如果为空则说明是有效的括号，否则不是有效的括号。

### 代码
```cpp
bool isValid(string s) {
	int len = s.size();
	stack<char> st;
	for( int i = 0; i < len; i++ ){
		if(s[i] == ')'){
			if(st.empty() || st.top() != '(') return false;
			else st.pop();
		}
		else if(s[i] == ']'){
			if(st.empty() || st.top() != '[') return false;
			else st.pop();
		}
		else if(s[i] == '}'){
			if(st.empty() || st.top() != '{') return false;
			else st.pop();
		}
		else st.push(s[i]);
	}
	return st.empty();
}
```
## 思考与拓展
### 思考
跟括号相关的题目利用堆栈一般都能解决。
### 拓展
如果输入的字符串 s 有非括号字符呢？
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
