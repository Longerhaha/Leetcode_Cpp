# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 066_(加1)Plus One
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。<br>
最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。<br>
你可以假设除了整数 0 之外，这个整数不会以零开头。<br>
### 1.2 输入与输出
输入：
* vector<int>& digits:由整数组成的非空数组所表示的非负整数

输出：
* vector<int>:加 1 后的非空数组所表示的非负整数
### 1.3 样例
#### 1.3.1 样例1
输入: [1,2,3]<br>
输出: [1,2,4]<br>
解释: 输入数组表示数字 123。<br>
#### 1.3.2 样例2
输入: [4,3,2,1]<br>
输出: [4,3,2,2]<br>
解释: 输入数组表示数字 4321。<br>
## 2 思路描述与代码	
### 2.1 思路描述（反序从低往高相加方法）
1. 进位 carry 初始化为1， 为了更加方便地进行加法，首先将 digits 反序
2. 然后从 digits 低位往高位进行加法，更新 carry 和记录当前位加法结果 ans
3. 反序 ans 并返回 ans

比如输入: [1, 2, 3]<br>
逆序后为 [3, 2, 1]<br>
carry 初始化为1<br>
3 + 1 = 4, carry = 0;<br>
2 + 0 = 2, carry = 0;<br>
1 + 0 = 1, carry = 0;<br>
carry = 0, 不需要再生成一个进位项。<br>
此时 ans = [4 2 1]，反序后为[1 2 4]。
### 2.2 代码
```cpp
vector<int> plusOne(vector<int>& digits) {
    vector<int> ans;
    reverse(digits.begin(), digits.end());
    int len = digits.size();
    int carry = 1;
    int sum = 0;
    for( int i = 0; i < len; i++ ){
        sum = (digits[i] + carry) % 10;
        ans.push_back(sum);
        carry = (digits[i] + carry) >= 10;
    }
    if(carry) ans.push_back(1);
    reverse(ans.begin(), ans.end());
    return ans;
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
反序从低往高相加|O(1)|O(n)
#### 3.1.3 难点分析
1. 边界测试，比如输入9, 99, 999, ..., 99...99的数组数据
### 3.2 拓展
如果给你输入的是两个数组呢？
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
