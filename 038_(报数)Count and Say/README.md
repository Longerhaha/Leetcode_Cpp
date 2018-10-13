# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 038_(报数)Count and Say
## 问题描述、输入输出与样例

### 问题描述
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
1.     1
2.     11
3.     21
4.     1211
5.     111221

1 被读作  "one 1"  ("一个一") , 即 11。

11 被读作 "two 1s" ("两个一"）, 即 21。

21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。


### 函数输入与输出

* 输入：
	* int n：第 n 项报数
* 输出：
	* string：第 n 项报数的结果字符串
	
### 问题样例

#### 示例1

输入: 1

输出: "1"

#### 示例2

输入: 4

输出: "1211"
	
	
## 思路描述与代码	
### 思路描述（计数法）
pre 记录第 n - 1 次报数的结果、 cur记录第 n 次报数的结果

第 n 次报数，pre 里面的数至少出现一次，所以 cnt 初始化为 1

```cpp
for(  int j = 0; j < pre.size(); j++ ){
	//扩大连续范围
	if(j + 1 < pre.size() && pre[j] == pre[j + 1]) cnt++;
	//搜索到不相同则记录
	else{
		char cnt_char = cnt + '0';
		cur.push_back(cnt_char);
		cur.push_back(pre[j]);
		cnt = 1;
	}
}
```
### 代码
```cpp
string countAndSay(int n) {
	string pre = "1";
	if(n == 1) return pre;
	for( int i = 2; i <= n; i++){
		//至少有一个，所以 cnt 初始化为 1
		int cnt = 1;
		string cur;
		for(  int j = 0; j < pre.size(); j++ ){
			//扩大连续范围
			if(j + 1 < pre.size() && pre[j] == pre[j + 1]) cnt++;
			//搜索到不相同则记录
			else{
				char cnt_char = cnt + '0';
				cur.push_back(cnt_char);
				cur.push_back(pre[j]);
				cnt = 1;
			}
		}
		//更替
		pre = cur;
		if(i == n) return cur;
	}
}
```
## 思考与拓展
### 思考

### 拓展



	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
