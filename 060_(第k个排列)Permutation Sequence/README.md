# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 060_(第k个排列)Permutation Sequence
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。<br>
按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"

给定 n 和 k，返回第 k 个排列。
### 1.2 输入与输出
输入：
* int n:集合[1,2,3,...,n]
* int k:第k个排列

输出：
* string:第k个排列的数字字符串
### 1.3 样例
#### 1.3.1 样例1
输入: n = 3, k = 3<br>
输出: "213"
#### 1.3.2 样例2
输入: n = 4, k = 9<br>
输出: "2314"
## 2 思路描述与代码	
### 2.1 思路描述（逐位判定法）
输入n时，我们对[1,2,3,…,n]进行排列，以第一位为首的排列的个数有 (n-1)! 个，比如我们要求第 k 个排列，则第 k 个排列的首位数字肯定是 (k-1) / (n-1)! + 1。以此同理可以推理到其他位。

比如样例1中输入 n = 3, k = 3，我们求 排序列表 num = [1,2,3] 的第 3 个排列。<br>
第1位是  (3 - 1) / 2! + 1 = 2，然后删除 2，num = [1,3]，k更新为  3 - 2! = 1；<br>
第2位是  (1 - 1) / 2! + 1 = 1，然后删除 1，num = [3], k 更新为 1 - 1! = 0；<br>
第3为是 nums[k] 即 3。<br>
所以输出"213"。
### 2.2 代码
```cpp
string getPermutation(int n, int k) {
    string ans;
    //num 为字符串"123...n"
    string num;
    for( int i = 1; i <= n; i++ ) num += (i + '0');
    //先算 (n - 1)!
    int rank = 1;
    for( int i = n - 1; i >= 1; i-- ) rank *= i;
    //k - 1方便与数组下标对应
    k--;
    //迭代求从高位到低位的数字
    for( int i = n - 1; i >= 1; i-- ){
        int idx = k / rank;
        ans += num[idx];
        //删除该字符后，此时 num 仍然是有序的
        num.erase(idx, 1);
        k = k - idx * rank;
        rank = rank / i;
    }
    ans += num[k];
    return ans;
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
逐位判定法|O(n)|最好O(n)，最差O(n^2)

空间复杂度主要要生成一个 num 字符串"123...n"。

时间复杂度主要集中在迭代判定位的for循环里，由于 k 对应的位置不好分析，所以这里只能给出最好与最差时间复杂度。<br>
最好时间复杂度: 比如求最后一个排列，即完全逆序的时候，此时 for 循环中的 nums.erase(idx, 1)操作的复杂度是O(1)，所以整个循环的复杂度是O(n)。<br>
最差时间复杂度：比如求第一个排列，即正序的时候，此时此时 for 循环中的 nums.erase(idx, 1)操作的复杂度是O(n)，所以整个循环的复杂度是O(n^2)。

#### 3.1.2 难点分析
1. 判断该位后需要更新阶乘、k并删除该字符，三个操作缺一不可。
### 3.2 拓展
本题可以利用[31 题求下一个排列](https://github.com/Longerhaha/Leetcode_Cpp/tree/master/031_(%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%8E%92%E5%88%97)Next%20Permutation)。其时间复杂度为O(nk)，空间复杂度为O(1),直接在其基础上改编即可。
	  
## 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
