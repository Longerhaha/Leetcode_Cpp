# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 131_(分割回文串)Palindrome Partitioning
## 问题描述与输入输出
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

### 问题样例

	示例1：
	输入:
	"aab"
	输出:
	[
	  ["aa","b"],
	  ["a","a","b"]
	]
	
	

函数输入与输出：
* 输入：
	* string s：给定的字符串s
* 输出：
	* vector<vector<string>>: s所有可能的切割方案

## 思路			
### DFS
	
	DFS(vector<vector<string>>& ans, vector<string>& path, string& s, int start){
		if(start == s.size()){
			ans.pushback(path);
			return ;
		}
		
		for( i = start; i < s.size; i++ ){
			if(isPalindrome(s.substr(start, i + 1 - start))){
				path.pushback(s.substr(start, i + 1 - start));
				DFS(ans, path, s, i + 1);
				path.popback();
			}
		}
	}
	
	从0开始DFS s字符串即可。
	
	
## 拓展与思考：
### 拓展
如果让你返回最少的分割数呢？如果你知道动态规划你应该知道怎么做。
### 思考
这是本人的第一个C++程序，具有很特别的意义。看了C++快一个月多，我开始写代码了。
本题不难，但是用C语言写起来则会很繁琐，C++写起来特别舒服、顺畅。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
