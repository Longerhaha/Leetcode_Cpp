# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 925_(长按键入)Long Pressed Name
## 问题描述、输入输出与样例

### 问题描述

你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

__提示__：

1. name.length <= 1000
2. typed.length <= 1000
3. name 和 typed 的字符都是小写字母。

### 函数输入与输出

* 输入：
	* string name：名字字符串
	* string typed：键入的名字字符串
* 输出：
	* bool：typed 是否是 name 的键入字符串（其中一些字符可能被长按）
	
### 问题样例

#### 示例1

输入：name = "alex", typed = "aaleex"

输出：true

解释：'alex' 中的 'a' 和 'e' 被长按。

#### 示例2

输入：name = "saeed", typed = "ssaaedd"

输出：false

解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。	

#### 示例3
输入：name = "leelee", typed = "lleeelee"

输出：true

#### 示例4
输入：name = "laiden", typed = "laiden"

输出：true

解释：长按名字中的字符并不是必要的。
	
## 思路描述与代码	
### 思路描述（常规法）
name_len 为 name 字符串的长度
typed_len 为 typed 字符串的长度
i 记录 name 遍历的位置
j 记录 typed 遍历的位置
```cpp
while(i < name_len && j < typed_len){
	//如果 name[i] 不与下一个字符相等则不需要跳跃可能重复键入的值
	if(i + 1 < name_len && name[i] == name[i + 1]){
		//如果与键入的值相等则下一个遍历
		if(typed[j] == name[i]) i++, j++;
		//如果不等则说明不匹配，返回false
		else return false;
	}
	//如果 name[i] 不与下一个字符相等则需要跳跃可能重复键入的值
	else{
		//如果不等则说明不匹配，返回false
		if(typed[j] != name[i]) return false;
		//相等则跳跃重复键入的值
		while(j < typed_len && typed[j] == name[i]) j++;
		i++;
	}
}
//如果 i 或 j 中有一个没有遍历结束，说明还有不匹配的地方，返回false
if(i != name_len || j != typed_len) return false;
//匹配
else return true;
```
### 代码
```cpp
bool isLongPressedName(string name, string typed) {
	int name_len = name.size();
	int typed_len = typed.size();
	int i = 0, j = 0;
	while(i < name_len && j < typed_len){
		if(i + 1 < name_len && name[i] == name[i + 1]){
			if(typed[j] == name[i]) i++, j++;
			else return false;
		}
		else{
			if(typed[j] != name[i]) return false;
			while(j < typed_len && typed[j] == name[i]) j++;
			i++;
		}
	}
	if(i != name_len || j != typed_len) return false;
	else return true;
}
```
## 思考与拓展
### 思考
本题较为简单。
### 拓展
暂无想法。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
