# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 929_(独特的邮电地址)Special Email Address
## 1 问题描述、输入输出与样例
### 1.1 问题描述
每封电子邮件都由一个本地名称和一个域名组成，以 @ 符号分隔。<br>
例如，在 alice@leetcode.com中， alice 是本地名称，而 leetcode.com 是域名。<br>
除了小写字母，这些电子邮件还可能包含 ',' 或 '+'。<br>
如果在电子邮件地址的本地名称部分中的某些字符之间添加句点（'.'），则发往那里的邮件将会转发到本地名称中没有点的同一地址。例如，"alice.z@leetcode.com” 和 “alicez@leetcode.com” 会转发到同一电子邮件地址。 （请注意，此规则不适用于域名。）<br>
如果在本地名称中添加加号（'+'），则会忽略第一个加号后面的所有内容。这允许过滤某些电子邮件，例如 m.y+name@email.com 将转发到 my@email.com。 （同样，此规则不适用于域名。）<br>
可以同时使用这两个规则。<br>
给定电子邮件列表 emails，我们会向列表中的每个地址发送一封电子邮件。实际收到邮件的不同地址有多少？<br>

__提示__：
1. 1 <= emails[i].length <= 100
2. 1 <= emails.length <= 100
3. 每封 emails[i] 都包含有且仅有一个 '@' 字符。
### 1.2 输入与输出
输入：<br>
* vector<string>& emails:字符串形式的邮件名列表<br>
输出：<br>
* int:实际收到邮件的不同地址的个数<br>
### 1.3 样例
#### 1.3.1 样例1
输入：["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]<br>
输出：2<br>
解释：实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。<br>
## 2 思路描述与代码	
### 2.1 思路描述（本地名称域名分割法）
1. 先找到　'@'　的出现位置，然后取出域名；
2. 根据规则（遇见'.'跳过，遇见第一个'+'舍去后面）处理本地名称；
3. 合并本地名称与域名。

比如对于地址："test.email+alex@leetcode.com"<br>
1. 对"test.email+alex@leetcode.com"先从右往做左找到 '@' 位置15，然后提取域名"@leetcode.com"；<br>
2. 从做往右遍历，遇见'.'跳过，遇见第一个'+'舍去后面，得到名称"testemail";<br>
3. 合并地址后为 "testemail@leetcode.com"。<br>
### 2.2 代码
```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        int len_emails = emails.size();
        for( int i = 0; i < len_emails; i++ ){
            int len_email = emails[i].size();
            int j = len_email - 1;
            //域名
            string domain;
            while(j >= 0 && emails[i][j] != '@') j--;
            domain += emails[i].substr(j, len_email - j);
            //本地名称
            string local_name;
            for( int k = 0; k < j; k++ ){
                if(emails[i][k] == '.') continue;
                else if(emails[i][k] == '+') break;
                else local_name += emails[i][k];
            }
            set.insert(local_name + domain);
            //cout << local_name + domain << endl;
        }
        return set.size();
    }
};
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
本地名称域名分割法|O(n)|O(n)
#### 3.1.3 难点分析
1. 使用何种数据结构能够使得识别重复的邮件地址。
### 3.2 拓展
本题可以用来做邮件过滤。
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
