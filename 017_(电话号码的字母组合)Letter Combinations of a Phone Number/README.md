# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 017_(电话号码的字母组合)Letter Combinations of a Phone Number
## 问题描述、样例与输入输出

### 问题描述

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

	2 ：{'a', 'b', 'c'}
	3 ：{'d', 'e', 'f'}
	4 ：{'g', 'h', 'i'}
	5 ：{'j', 'k', 'l'}
	6 ：{'m', 'n', 'o'}
	7 ：{'p', 'q', 'r', 's'}
	8 ：{'t', 'u', 'v'}
	9 ：{'w', 'x', 'y', 'z'}}

### 问题样例

	示例1:
	输入: 
	"23"
	  
	输出: 
	["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
	
### 函数输入与输出

* 输入：
	* string digits：以字符串形式输入
* 输出：
	* vector<string>：组合而成的字符串列表

## 思路	
### DFS

    const vector<vector<char>> phone{{}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'},
                               {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    
    void letterCombinations_dfs(vector<string> &ans, string &digits, int idx, string& path){
        //递归到尾巴的时候保存一下路径
        if(idx == digits.size()){
            ans.push_back(path);
            return ;
        }
        //对所有可能DFS
        for( int j = 0; j < phone[int(digits[idx] - '1')].size(); j++ ){
            path.push_back(phone[int(digits[idx] - '1')][j]);
            letterCombinations_dfs(ans, digits, idx + 1, path);
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        int len = digits.size();
        string path;
        letterCombinations_dfs(ans, digits, 0, path);
        return ans;
    }

		

 
## 拓展与思考：
### 拓展
暂无想法。
### 思考
本题，直接DFS即可。	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
