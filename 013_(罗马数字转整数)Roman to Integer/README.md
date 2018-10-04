# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 013_(罗马数字转整数)Roman to Integer
## 问题描述、输入输出与样例

### 问题描述
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

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

给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。


### 函数输入与输出

* 输入：
	* string s：罗马数字字符串
* 输出：
	* int：转换后的整数
	
### 问题样例

#### 示例1

输入: "III"

输出: 3

#### 示例2

输入: "IV"

输出: 4

#### 示例3

输入: "IX"

输出: 9

#### 示例4

输入: "LVIII"

输出: 58

解释: L = 50, V= 5, III = 3.

#### 示例5

输入: "MCMXCIV"

输出: 1994

解释: M = 1000, CM = 900, XC = 90, IV = 4.
	
## 思路描述与代码	
### 思路描述（常规方法）

对于字符 C、 X、 I 要么是减去其对应的值，要么加上其对应的值，取决于后面的字母。

其余字符则加上其值即可。

### 代码
	
	int romanToInt(string s) {
        unordered_map<char, int> mp {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int conversion = 0;
        
        int len_s = s.size();
        for( int i = 0; i < len_s; i++ ){
            if(s[i] == 'C' && (i + 1) < len_s){
                if(s[i + 1] == 'D' || s[i + 1] == 'M')
                    conversion -= 100;
                else
                    conversion += 100;
            }
            else if(s[i] == 'X' && (i + 1) < len_s){
                if(s[i + 1] == 'L' || s[i + 1] == 'C')
                    conversion -= 10;
                else
                    conversion += 10;
            }
            else if(s[i] == 'I' && (i + 1) < len_s){
                if(s[i + 1] == 'V' || s[i + 1] == 'X')
                    conversion -= 1;
                else
                    conversion += 1;
            }
            else conversion += mp[s[i]];
        }
        return conversion;
    }
 
 
## 思考与拓展
### 思考
本题较为简单。
### 拓展
暂无想法。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
