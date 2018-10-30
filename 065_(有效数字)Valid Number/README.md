# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 065_(有效数字)Valid Number
## 1 问题描述、输入输出与样例
### 1.1 问题描述
验证给定的字符串是否为数字。
### 1.2 输入与输出
输入：
* string s:输入的字符串 s

输出：
* bool:是否是有效的数字
### 1.3 样例
#### 1.3.1 样例1
输入: "0"<br>
输出: true<br>
#### 1.3.2 样例2
输入: " 0.1 "<br>
输出: true<br>
#### 1.3.3 样例3
输入: "abc"<br>
输出: false<br>
#### 1.3.4 样例4
输入: "1 a"<br>
输出: false<br>
#### 1.3.5 样例5
输入: "2e10"<br>
输出: true<br>

## 2 思路描述与代码	
### 2.1 思路描述（状态机方法）
我们把有效的数字统一为如下两种模式：<br>
空格串（可选） + 底数的整数部分 + 底数的小数部分（可选） + 指数（可选） + 空格串（可选）<br>
空格串（可选） + 底数的小数部分 + 指数（可选） + 空格串（可选）<br>

除去开头空格串，第 1 种方式有8种情况，第 2 中方式有4种情况。分别如下：
1. 底数的整数部分
2. 底数的整数部分 + 空格串
3. 底数的整数部分 + 指数 
4. 底数的整数部分 + 指数 + 空格串
5. 底数的整数部分 + 底数的小数部分
6. 底数的整数部分 + 底数的小数部分 + 空格串
7. 底数的整数部分 + 底数的小数部分 + 指数
8. 底数的整数部分 + 底数的小数部分 + 指数 + 空格串
9. 底数的小数部分 
10. 底数的小数部分 + 空格串
11. 底数的小数部分 + 指数
12. 底数的小数部分 + 指数 + 空格串

我们把上述情况建立一个状态机，其中状态 0 表示搜索底数的整数部分(保证存在，但不知道是不是有效的)，状态 1 表示搜索底数的小数部分(保证存在，但不知道是不是有效的)，状态 2 表示搜索指数部分(保证存在，但不知道是不是有效的)。<br>
以下为解题步骤：<br>

    search 记录当前搜索字符在字符串 s 中的下标
    先跳过开头的空格串并保证有底数存在
    while( search < len){
        在状态0有：
            * if 在状态 0 遇见了空格 ' ' ：
                * 跳过空格串，如果刚好跳到尾巴则是有效的数字(情况2)，否则不是有效的数字
            * else if 在状态 0 遇见了小数点 '.' ：
                * if 恰好此时 '.' 在最后一个位置此时就是合法的数字(情况1)
                * if 遇见了'.d(0-9)xx...x'、'.exx...x'、'.Exx...x'、'. xx...x'则跳转到状态 1 ，else 返回 false
            * else if 在状态 0 遇见了指数标识 'e' 或 'E':
                * if(存在符号位) 跳过符号位
                * if(存在可能的有效指数) 跳转至状态 2 , else 返回 false
            * else if 在状态 0 遇见了非法字符
                * 返回 false
            search++,搜索下一位
        在状态1有：
            * if 在状态 1 遇见了空格 ' ' ：
                * 跳过空格串，如果刚好跳到尾巴则是有效的数字(情况6、10)，否则不是有效的数字
            * else if 在状态 1 遇见了指数标识 'e' 或 'E':
                * if(存在可能的有效指数) 跳转至状态 2 , else 返回 false
            * else if 在状态 1 遇见了非法字符
                * 返回 false
            search++,搜索下一位
        在状态2有：
            * if 在状态 2 遇见了空格 ' ' ：
                * 跳过空格串，如果刚好跳到尾巴则是有效的数字(情况4、8、12)，否则不是有效的数字
            * else if 在状态 2 遇见了非法字符
                * 返回 false
            search++,搜索下一位
    }
    其他情况则可以遍历成功，返回true。
### 2.2 代码
```cpp
bool isNumber(string s) {
    int len = s.size();
    int search = 0;
    //1. 先跳过空格
    while( search < len && s[search] == ' ') search++;
    if(search == len) return false;
    //2. 跳过符号位
    if(search < len && (s[search] == '-' || s[search] == '+')) search++;
    //3. 检查经过上述两个步骤后的输入是不是合法的，如果合法则能够进入状态0进行后续操作，如果不合法输出false
    //能进入状态0的情况有：
    //(1)数字开头
    //(2)小数点开头且小数点后的第一位是数字
    if((s[search] >= '0' && s[search] <= '9') || (search + 1 < len && s[search] == '.' &&  s[search + 1] >= '0' && s[search + 1] <= '9' )) ;
    else return false;
    
    //设置状态机
    //其中状态 0 表示搜索底数的整数部分(保证存在，但不知道是不是有效的)
    //状态 1 表示搜索底数的小数部分(保证存在，但不知道是不是有效的)
    //状态 2 表示搜索指数部分(保证存在，但不知道是不是有效的)
    int state = 0;
    while( search < len ){
        switch(state){
            case 0: {
                if(s[search] == ' '){
                    //类型：底数的整数部分 + 空格串
                    while( search < len && s[search] == ' ') search++;
                    if(search == len) return true;
                    else return false;
                }
                else if(s[search] == '.'){
                    // 类型：底数的整数部分
                    if(search == len - 1) return true;
                    // 跳到状态1
                    else if(s[search + 1] != ' ' && s[search + 1] != 'e' && s[search + 1] != 'E' && (s[search + 1]  < '0' || s[search + 1] > '9')) return false;
                    state = 1;
                }
                // 跳到状态2
                else if(s[search] == 'e' || s[search] == 'E'){
                    if(search + 1 < len && (s[search + 1] == '-' || s[search + 1] == '+')) search++;
                    if(search == len - 1 || (s[search + 1]  < '0' || s[search + 1] > '9')) return false;
                    state = 2;
                }
                else if(s[search] < '0' || s[search] > '9') return false;
                search++;
                break;
            }
            case 1:{
                if(s[search] == ' '){
                    //类型：底数的整数部分 + 底数的小数部分 + 空格串
                    //类型：底数的小数部分 + 空格串
                    while( search < len && s[search] == ' ') search++;
                    if(search == len) return true;
                    else return false;
                }
                //跳转至状态2
                else if(s[search] == 'e' || s[search] == 'E'){
                    if(search + 1 < len && (s[search + 1] == '-' || s[search + 1] == '+')) search++;
                    if(search == len - 1 || (s[search + 1]  < '0' || s[search + 1] > '9')) return false;
                    state = 2;
                }
                else if(s[search] < '0' || s[search] > '9') return false;
                search++;
                break;
            }
            case 2:{
                //类型：底数的整数部分 + 指数 + 空格串
                //类型：底数的整数部分 + 底数的小数部分 + 指数 + 空格串
                //类型：底数的小数部分 + 指数 + 空格串
                if(s[search] == ' '){
                    while( search < len && s[search] == ' ') search++;
                    if(search == len) return true;
                    else return false;
                }
                else if(s[search] < '0' || s[search] > '9') return false;
                search++;
                break;
            }
           default:break;
        }
    }
    //其他类型
    return true;
}
```
## 3 思考与拓展
### 3.1 思考
无。
#### 3.1.1 其他方法
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
状态机法|O(1)|O(n)
#### 3.1.3 难点分析
1. 统一化有效的数字的格式；
2. 状态跳转；
3. 类型列举全。
### 3.2 拓展
如果给你的是数组数据或者是链表数据呢？
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
