# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 049_(字母异位词分组)Group Anagrams
## 问题描述、输入输出与样例

### 问题描述

给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

__说明__：

* 所有输入均为小写字母。
* 不考虑答案输出的顺序。

### 函数输入与输出

* 输入：
	* vector<string>& strs：输入的字符串数组
* 输出：
	* vector<vector<string>>：分组后的字符串组
	
### 问题样例

#### 示例1

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]

输出:

	[
	  ["ate","eat","tea"],
	  ["nat","tan"],
	  ["bat"]
	]	
	
## 思路描述与代码	
### 思路描述（基于字符计数的分组法）
利用哈希表来分组，哈希表的 key 是字符计数结果的字符串。

比如["11100....0"(26个小写字母出现的次数):["abc", "acb", "cab"]]

### 代码
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	//分组的矢量
	vector<vector<string>> groups;
	//利用 map 来分组
	unordered_map<string, vector<string>> map;
	int len_strs = strs.size();
	for( int i = 0; i < len_strs; i++ ){
		//字符计数的结果作为 key
		string str_cnt(26, '0');
		for( int j = 0; j < strs[i].size(); j++ ) str_cnt[strs[i][j] - 'a']++;
		if(map.count(str_cnt) == 0){
			vector<string> group;
			map[str_cnt] = group;
		}
		auto it = map.find(str_cnt);
		(it->second).push_back(strs[i]);
	}
	
	unordered_map<string, vector<string>>::iterator iter;
	for( iter = map.begin(); iter != map.end(); iter++ ){
		groups.push_back(iter->second);
	}
	return groups;
}
```
## 思考与拓展
### 思考
基于字符计数的分组法时间复杂度与空间复杂度都是O（nk），其中 k 是字符串数组中字符串的最大长度。本题还可以使用基于排序的分组法，但是时间复杂度是O（nklogk）。
### 拓展
可以试一下使用基于排序的分组法。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
