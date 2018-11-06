# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 071_(简化路径)Simplify Path
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个文档 (Unix-style) 的完全路径，请进行路径简化。<br>
__边界情况__:<br>
* 你是否考虑了 路径 = "/../" 的情况？在这种情况下，你需返回 "/" 。
* 此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。在这种情况下，你可忽略多余的斜杠，返回 "/home/foo"
### 1.2 输入与输出
输入：
* string path:输入文档的完全路径的字符串

输出：
* string:简化后的文档完全路径字符串

### 1.3 样例
#### 1.3.1 样例1
输入: "/home/"<br>
输出: "/home"<br>
#### 1.3.2 样例2
输入: "/a/./b/../../c/"<br>
输出: "/c"<br>
## 2 思路描述与代码	
### 2.1 思路描述（常规法）
simplifyPathWord记录简化路径中记录的单词列表<br>
1. 首先跳过连续的字符'/'<br>
2. 找到被左右两个'/'包围的单词<br>
* 如果该单词是'.'或者为空则继续查找下一个单词<br>
* 如果该单词是'..'则抛弃上一个路径, 即从 simplifyPathWord 弹出一个单词<br>
* 否则则是合理的单词，加入simplifyPathWord<br>
3. 重复上述过程直至遍历 path<br>

比如输入 "/a/./b/../../c/"<br>
先找到单词 "a", 合理的单词，加入到单词列表，simplifyPathWord = ["a"]<br>
再找到单词 ".", 跳过, simplifyPathWord = ["a"]<br>
再找到单词 "b", 合理的单词，加入到单词列表，, simplifyPathWord = ["a", "b"]<br>
再找到单词 "..", 需把上一个路径抛弃，, simplifyPathWord = ["a"]<br>
再找到单词 "..", 需把上一个路径抛弃，, simplifyPathWord = []<br>
再找到单词 "c", 合理的单词，加入到单词列表, simplifyPathWord =["c"]<br>
从而得到简化的路径为"/c"<br>

### 2.2 代码
```cpp
string simplifyPath(string path) {
    string ans;
    int len = path.size();
    int search = 0;
    vector<string> simplifyPathWord;
    while( search < len ){
        while(search < len && path[search] == '/') search++;
        string word;
        while(search < len && path[search] != '/') word += path[search++];
        if(word.size() == 0 || word.compare(".") == 0) continue;
        else if(word.compare("..") == 0){
           if(simplifyPathWord.size() != 0) simplifyPathWord.pop_back(); 
        }
        else simplifyPathWord.push_back(word);
    }
    
    if(simplifyPathWord.size() == 0) return "/";
    else{
        for( int i = 0; i < simplifyPathWord.size(); i++ ){
            ans += '/';
            ans += simplifyPathWord[i];
        }
        return ans;
    }
    
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
常规法|O(1)|O(n)
#### 3.1.3 难点分析
1. 找到被左右两个'/'包围的单词
2. 分析路径简化的规则
### 3.2 拓展
无。
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
