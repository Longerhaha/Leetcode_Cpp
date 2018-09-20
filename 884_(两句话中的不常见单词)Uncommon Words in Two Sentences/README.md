# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 884_(两句话中的不常见单词)Uncommon Words in Two Sentences
## 问题描述、输入输出与样例

### 问题描述

给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）

如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。

返回所有不常用单词的列表。

您可以按任何顺序返回列表。

### 函数输入与输出

* 输入：
	* string A：句子A
	* string B：句子B
* 输出：
	* vector<string>：不常用单词的列表
	
### 问题样例

	示例1:
	输入: 
	A = "this apple is sweet", B = "this apple is sour"
	  
	输出: 
	["sweet","sour"]
	
	示例2:
	输入: 
	A = "apple apple", B = "banana"
	  
	输出: 
	["banana"]
	
	提示：

	1. 0 <= A.length <= 200
	2. 0 <= B.length <= 200
	3. A 和 B 都只包含空格和小写字母。
	
	
## 思路描述与代码	
### 思路描述（multiset）
	
1. 提取句子A、B中的单词
2. 将A、B中的单词加入到 multiset
3. 遍历 A 的单词，如果在 A 单词集合中只出现一次且不再 B 中出现，则加入到不常用单词的列表，依此遍历 B 的单词。


### 代码

	vector<string> uncommonFromSentences(string A, string B) {
        vector<string> ans;
        //1. 提取单词
        vector<string> strA;
        int startA = 0;
        for( int i = 0; i < A.size(); i++ ){
            if(A[i] == ' '){
                strA.push_back(A.substr(startA, i - startA));
                startA = i + 1;
            }
            else if(i == A.size() - 1){
                strA.push_back(A.substr(startA, i - startA + 1));
            }
        }
        vector<string> strB;
        int startB = 0;
        for( int i = 0; i < B.size(); i++ ){
            if(B[i] == ' '){
                strB.push_back(B.substr(startB, i - startB));
                startB = i + 1;
            }
            else if(i == B.size() - 1){
                strB.push_back(B.substr(startB, i - startB + 1));
            }
        }
        //2. 单词加入 multiset 中
        unordered_multiset<string> setA;
        unordered_multiset<string> setB;
        for( auto str : strA ) setA.insert(str);
        for( auto str : strB ) setB.insert(str);

        //3. 判断是否是不常见的单词
        for( auto str : strA){
            cout << str << ":" << setA.count(str) << endl;
            if(setA.count(str) == 1 && setB.count(str) <= 0)
                ans.push_back(str);
        }
        for( auto str : strB){
            if(setB.count(str) == 1 && setA.count(str) <= 0)
                ans.push_back(str);
        }
        
        return ans;
    }
 
## 拓展与思考：
### 拓展
暂无。
### 思考
本题利用 multiset 可以很简单的解决该问题。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
