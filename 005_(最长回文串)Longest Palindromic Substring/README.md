# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 005_(最长回文串)Longest Palindromic Substring
## 问题描述、输入输出与样例

### 问题描述

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

### 函数输入与输出

* 输入：
	* string s：给定的字符串 s
* 输出：
	* string：s中最长的回文子串
	
### 问题样例

#### 示例1

输入: "babad"

输出: "bab"

注意: "aba"也是一个有效答案。
	
#### 示例2

输入: "cbbd"

输出: "bb"

## 思路描述与代码	
### 思路描述（Manacher's Algorithm）

[Manacher](https://articles.leetcode.com/longest-palindromic-substring-part-ii/)结合了滑窗与回文串的对称性来简化算法。

在当前窗（有中心 C ，右边界 R ）内，利用对称性来求以该点为中心的最长回文串的长度。

算法主要部分如下：

1. 比如某点 i，其有关于 C 的一个镜像位置 i_mirror = 2 * C - i，镜像对应的回文长度为P[i_mirror]

2. 如果 i + P[i_mirror] < R，则 P[i] = P[i_mirror]（对称性），否则暂定 P[i] = R - C

3. 扩张 P[i] 直至无法扩张

4. 若 i + P[i] 超越了右边界，则更新窗。

值得注意的是上述无法解决最长回文长度为偶数的情况，于是需要对输入的字符串进行预处理。

### 代码

	string preProcess(string s) {
        string deal_s(s);
        deal_s.insert(0, 1, '#');
        for( int i = 1; i <= s.size(); i++)
            deal_s.insert(2*i, 1, '#');
        return deal_s;
    }
    string longestPalindrome(string s) {
        string prep_s = preProcess(s);
        int R = 0, C = 0;
        int prep_s_len = prep_s.size();
        //P[i] 代表以 prep_s[i] 为中心的最长回文串的长度
        vector<int> P(prep_s_len, 0);
        for( int i = 0; i < prep_s_len; i++ ){
            //先获得镜像的位置
            int i_mirror = 2 * C - i;
            // 1. 如果 i 在当前最大最长回文串的长度的右边界 R 内，则 P[i] = min(R - i, P[i_mirror])
            //  P[i] = min(R - i, P[i_mirror])是因为其可能跨越右边界
            // 2. 否则就先给0
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            //尝试扩张
            while (i - 1 - P[i] >= 0 && i + 1 + P[i] < prep_s_len && prep_s[i + 1 + P[i]] == prep_s[i - 1 - P[i]]) P[i]++;
            //如果跳出当前最长回文串的覆盖范围则更新 R 和 C
            if( i + P[i] > R){
                R = i + P[i];
                C = i;
            }
        }
        
        //遍历查找最大值
        int max_p = 0, max_p_idx = 0;
        for( int i = 0; i < prep_s_len; i++ ){
            if(P[i] > max_p) max_p_idx = i, max_p = P[i];
        }
    
        return s.substr((max_p_idx - max_p) / 2, max_p);
    }
 
## 拓展与思考：
### 拓展
暂无。
### 思考
本题也可使用二维 DP 做，但是空间复杂度为O(n^2)。Manacher算法是一个很好的思想，理解起来也不难。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
