# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 012_(整数转罗马数字)Integer to Roman
## 问题描述、输入输出与样例

### 问题描述

罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

* I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
* X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
* C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

### 函数输入与输出

* 输入：
	* int num：需要转换的数字的值
* 输出：
	* string：对 num 进行罗马数字转换后的字符串
	
### 问题样例

#### 示例1

输入: 3

输出: "III"

#### 示例2

输入: 4

输出: "IV"

#### 示例3

输入: 9

输出: "IX"

#### 示例4

输入: 58

输出: "LVIII"

解释: C = 100, L = 50, XXX = 30, III = 3.

#### 示例5

输入: 1994

输出: "MCMXCIV"

解释: M = 1000, CM = 900, XC = 90, IV = 4.
	
	
## 思路描述与代码	
### 思路描述（常规法）

带有优先权的去判断属于哪个范围，然后做响应的操作。


### 代码

	string intToRoman(int num) {
        string conversion;
        while(num > 0){
            if(num >= 1000) conversion += 'M', num -= 1000;
            else if(num >= 900) conversion += "CM", num -= 900;
            else if(num >= 500) conversion += 'D', num -= 500;
            else if(num >= 400) conversion += "CD", num -= 400;
            else if(num >= 100) conversion += 'C', num -= 100;
            else if(num >= 90) conversion += "XC", num -= 90;
            else if(num >= 50) conversion += 'L', num -= 50;
            else if(num >= 40) conversion += "XL", num -= 40;
            else if(num >= 10) conversion += 'X', num -= 10;
            else if(num >= 9) conversion += "IX", num -= 9;
            else if(num >= 5) conversion += 'V', num -= 5;
            else if(num >= 4) conversion += "IV", num -= 4;
            else conversion += 'I', num -= 1;
        }
        cout << num;
        return conversion;
    }
 
## 思考与拓展
### 思考
本文的方法虽然不是最好的，但是是很好理解的。

换另外一种思路你可以这么做，在某个范围内进行判断，然后一直减去相应的值直到不在这个范围，然后去判断下个范围，以此不断循环，这样可以节省很多无效的if判断开销。

### 拓展
如果让你把罗马数字转化为阿拉伯数字呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
