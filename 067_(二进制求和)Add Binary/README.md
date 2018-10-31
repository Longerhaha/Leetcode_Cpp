# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 067_(二进制求和)Add Binary
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定两个二进制字符串，返回他们的和（用二进制表示）。<br>
输入为非空字符串且只包含数字 1 和 0。<br>
### 1.2 输入与输出
输入：
* string a:输入的非空二进制字符串 a
* string b:输入的非空二进制字符串 b

输出：
* string:两个二进制字符串的和的二进制字符串
### 1.3 样例
#### 1.3.1 样例1
输入: a = "11", b = "1"<br>
输出: "100"<br>
#### 1.3.2 样例2
输入: a = "1010", b = "1011"<br>
输出: "10101"<br>
## 2 思路描述与代码	
### 2.1 思路描述（反转位运算方法）
1. 将数组的二进制字符串 a 和 b 反转
2. 从低位往高位进行二进制全加器的位运算，如果遍历是下标超出了 a 的范围或 b 的范围则将其二进制设置为0
3. 如果遍历后有进位则继续生成一个1
4. 将记录的二进制加法的结果反序

比如输入: a = "1010", b = "10110"<br>
反序后 a = "0101"，b = "01101"<br>
进位初始化为0，从低位往高位进行加法:<br>
0 + 0 + 0 = 0, carry = 0, ans = [0]<br>
1 + 1 + 0 = 0, carry = 1, ans = [0, 0]<br>
0 + 1 + 1 = 0, carry = 1, ans = [0, 0, 0]<br>
1 + 0 + 1 = 0, carry = 1, ans = [0, 0, 0, 0]<br>
此时超出 a 的位宽，所以设置 a 的加法系数为0<br>
0 + 1 + 1 = 1, carry = 1, ans = [0, 0, 0, 0]<br>
carry = 1, ans = [0, 0, 0, 0, 1]<br>
反序后 ans = [1, 0, 0, 0, 0] <br>
### 2.2 代码
```cpp
//位运算
string addBinary(string a, string b) {
    string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len_a = a.size();
    int len_b = b.size();
    bool sum = 0;
    bool carry = 0;
    int i = 0;
    while( i < max(len_a, len_b) || carry ){
        bool bool_a = i >= len_a ? false : (a[i] - '0' > 0);
        bool bool_b = i >= len_b ? false : (b[i] - '0' > 0);
        sum = carry ^ bool_a ^ bool_b;
        ans.push_back(sum + '0');
        carry = (carry & bool_a) | (carry & bool_b) | (bool_a & bool_b);
        i++;
    }
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
反转位运算|O(1)|O(n)
#### 3.1.3 难点分析
1. 最后一个进位的处理
2. 全加器的位运算方法
### 3.2 拓展
如果输入的是x(x>2)组二进制字符串呢？
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
