# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 387_(字符串中的第一个唯一字符)First Unique Character in a String
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
### 1.2 输入与输出
输入：
* string s：输入的字符串s

输出：
* int:它的第一个不重复的字符的索引
### 1.3 样例
#### 1.3.1 样例1
输入:s = "leetcode"<br>
输出:返回 0<br>
 
#### 1.3.2 样例2
输入: s = "loveleetcode"<br>
输出: 2<br>
## 2 思路描述与代码	
### 2.1 思路描述（字典法）
dict[c] 记录字符 c 的数目，一遍扫描记录字符串 s 中的所有字符的数目<br>
然后再一遍扫描 s，当 s 中字符 c 只出现一次即dict[c] = 1时返回下标，如果没有这样的字符则返回-1<br>

比如输入s = "leetcode"，一遍扫描后有:<br>
dict['c'] = 1, dict['d'] = 1, dict['e'] = 3, dict['l'] = 1, dict['o'] = 1, dict['t'] = 1<br>
然后再次一遍扫描s，发现dict['l'] = 1，返回此时遍历的索引 0<br>

### 2.2 代码
```cpp
int firstUniqChar(string s) {
    vector<int> dict(26, 0);
    int len = s.size();
    for( int i = 0; i < len; i++ ) dict[s[i] - 'a'] += 1;
    for( int i = 0; i < len; i++ ){
        if(dict[s[i] - 'a'] == 1) return i;
    }
    return -1;
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
##### 3.1.1.1 字典+队列法
dict[c] 记录字符 c 的数目，队列 q 保存的是在遍历过程中在 s 中按前后顺序出现出现过的字符极其下标，相同字符只记录一次<br>

然后遍历队列里面的元素，当 s 中字符 c 只出现一次即dict[c] = 1时返回下标。

#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
字典法|O(1)|O(n)
字典+队列法|O(n)|O(n)，平均复杂度更低，应该运行更快
#### 3.1.3 难点分析
1. 如何查重即多个相同的字符
2. 如何按先后顺序记录只出现一次的字符
### 3.2 拓展
如果给你的是链表数据或者数组数据呢？
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
