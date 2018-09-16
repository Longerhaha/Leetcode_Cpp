# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 893_(特殊等价字符串组)Num Special Equivalent Groups
## 问题描述与输入输出
你将得到一个字符串数组 A。

如果经过任意次数的移动，S == T，那么两个字符串 S 和 T 是特殊等价的。

 
一次移动包括选择两个索引 i 和 j，且 i％2 == j％2，并且交换 S[j] 和 S [i]。

现在规定，A 中的特殊等价字符串组是 A 的非空子集 S，这样不在 S 中的任何字符串与 S 中的任何字符串都不是特殊等价的。

 
返回 A 中特殊等价字符串组的数量。

### 问题样例

	示例1：
	输入:
	["a","b","c","a","c","c"]
	输出:
	3
	解释：
	3 组 ["a","a"]，["b"]，["c","c","c"]
	
	示例2：
	输入:
	["aa","bb","ab","ba"]
	输出:
	4
	解释：
	4 组 ["aa"]，["bb"]，["ab"]，["ba"]
	
	示例3：
	输入:
	["abc","acb","bac","bca","cab","cba"]
	输出:
	3
	解释：
	3 组 ["abc","cba"]，["acb","bca"]，["bac","cab"]

	示例4：
	输入:
	["abcd","cdab","adcb","cbad"]
	输出:
	1
	解释：
	1 组 ["abcd","cdab","adcb","cbad"]

函数输入与输出：
* 输入：
	* vector<string>& A：字符串数组的引用
* 输出：
	* int：A 中特殊等价字符串组的数量。

## 思路			
### 基于奇偶排序哈希统计法
	
	对A中的每个字符串s：
		提取s的偶数位矢量even
		提取s的奇数位矢量odd
		even排序、odd排序
		将even+odd组成的字符串插入unordered_map
	返回unordered_map的大小
	
## 拓展与思考：
### 拓展
暂无
### 思考
本题重在排序，从而使同一组元素的字符串even+odd一致，再利用哈希表的无重复性直接返回哈希表中已有的元素的数目即可。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
